#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#ifdef _WIN32
#include <windows.h>
#endif

// Helper that splits a string by a delimiter
// Parameters: const string s and char delimiter
// Returns: vector of strings that were split
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> parts;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        parts.push_back(item);
    }
    return parts;
}

// Extract the first UTF-8 character from a string
std::string getFirstUtf8Char(const std::string& str) {
    if (str.empty()) return "";
    
    unsigned char c = str[0];
    size_t len = 1;
    
    // Determine the length of the UTF-8 character
    if ((c & 0x80) == 0) {
        len = 1;  // ASCII
    } else if ((c & 0xE0) == 0xC0) {
        len = 2;  // 2-byte UTF-8
    } else if ((c & 0xF0) == 0xE0) {
        len = 3;  // 3-byte UTF-8 (most Chinese characters)
    } else if ((c & 0xF8) == 0xF0) {
        len = 4;  // 4-byte UTF-8
    }
    
    return str.substr(0, len);
}

// Find position of a UTF-8 string within another UTF-8 string
size_t findUtf8(const std::string& haystack, const std::string& needle) {
    return haystack.find(needle);
}

// Post-process the romanization according to phonological rules
std::string postProcess(const std::string& romanization) {
    std::string result = romanization;
    
    // Rule 1: Remove double 'r' (rr -> r)
    size_t pos = 0;
    while ((pos = result.find("rr", pos)) != std::string::npos) {
        result.erase(pos, 1);  // Remove one 'r'
        pos++;  // Move past the remaining 'r'
    }
    
    // Rule 2: When initial ends with 'y' and final starts with 'i',
    // remove the 'i' ONLY IF there's another vowel (a, e, o, u) after it
    pos = 0;
    while ((pos = result.find("yi", pos)) != std::string::npos) {
        // Check if there's a character after "yi"
        if (pos + 2 < result.length()) {
            char next_char = result[pos + 2];
            // If the next character is a vowel other than 'i', remove the 'i'
            if (next_char == 'a' || next_char == 'e' || next_char == 'o' || next_char == 'u') {
                result.erase(pos + 1, 1);  // Remove the 'i'
            }
        }
        pos++;
    }
    
    return result;
}

// Add tone markers to the romanization
std::string addToneMarkers(const std::string& romanization, const std::string& tone) {
    // Do nothing for 平 (level) or 入 (entering) tones
    if (tone == "平" || tone == "入") {
        return romanization;
    }
    
    std::string result = romanization;
    
    // Find the first vowel in the romanization
    for (size_t i = 0; i < result.length(); ++i) {
        char c = result[i];
        
        // Check if this is a vowel
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            std::string replacement;
            
            // 上 (rising) tone: add macron (flat bar)
            if (tone == "上") {
                if (c == 'a') replacement = "ā";
                else if (c == 'e') replacement = "ē";
                else if (c == 'i') replacement = "ī";
                else if (c == 'o') replacement = "ō";
                else if (c == 'u') replacement = "ū";
            }
            // 去 (departing) tone: add acute accent (rising mark)
            else if (tone == "去") {
                if (c == 'a') replacement = "á";
                else if (c == 'e') replacement = "é";
                else if (c == 'i') replacement = "í";
                else if (c == 'o') replacement = "ó";
                else if (c == 'u') replacement = "ú";
            }
            
            // Replace the vowel with its accented version
            if (!replacement.empty()) {
                result.replace(i, 1, replacement);
            }
            
            // Only replace the first vowel, then stop
            break;
        }
    }
    
    return result;
}

int main() {
#ifdef _WIN32
    // Set console code page to UTF-8 on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // open input file
    std::ifstream fin("input.txt");
    if (!fin) {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    // open output file with UTF-8 encoding
    std::ofstream fout("output.txt");
    if (!fout) {
        std::cerr << "Failed to create output.txt\n";
        return 1;
    }

    // mappings, can be expanded and customized to any scheme
    std::map<std::string, std::string> initial_map = {
        {"幫", "p"},
        {"滂", "ph"},
        {"並", "b"},
        {"明", "m"},

        {"端", "t"},
        {"透", "th"},
        {"定", "d"},
        {"泥", "n"},

        {"知", "tr"},
        {"徹", "thr"},
        {"澄", "dr"},
        {"孃", "nr"},

        {"精", "ts"},
        {"清", "tsh"},
        {"從", "dz"},
        {"心", "s"},
        {"邪", "z"},

        {"莊", "tsr"},
        {"初", "tshr"},
        {"崇", "dzr"},
        {"生", "sr"},
        {"俟", "zr"},

        {"章", "tsy"},
        {"昌", "tshy"},
        {"常", "dzy"},
        {"書", "sy"},
        {"船", "zy"},

        {"見", "k"},
        {"溪", "kh"},
        {"羣", "g"},
        {"疑", "ng"},

        {"曉", "h"},
        {"匣", "gh"},
        {"影", "'"},
        {"云", "gh"},

        {"以", "y"},
        {"來", "l"},
        {"日", "ny"}
    };

    std::map<std::string, std::string> final_map = {
        {"東一", "ung"},
        {"東三", "iung"},
        {"屋一", "uk"},
        {"屋三", "iuk"},

        {"冬", "uong"},
        {"沃", "uok"},
        {"鍾", "iuong"},
        {"燭", "iuok"},

        {"江", "rong"},
        {"覺", "rok"},

        // 支 - has both A/B and 開/合
        {"支A", "ie"},
        {"支B", "rie"},
        {"開|支", "ie"},
        {"合|支", "iue"},
        {"開|支A", "ie"},
        {"合|支A", "iue"},
        {"開|支B", "rie"},
        {"合|支B", "riue"},

        // 脂 - has both A/B and 開/合
        {"脂A", "i"},
        {"脂B", "ri"},
        {"開|脂", "i"},
        {"合|脂", "ui"},
        {"開|脂A", "i"},
        {"合|脂A", "ui"},
        {"開|脂B", "ri"},
        {"合|脂B", "rui"},

        {"之", "ii"},

        // 微 - has 開/合
        {"微", "iy"},
        {"開|微", "iy"},
        {"合|微", "uiy"},

        {"魚", "io"},
        {"模", "uo"},
        {"虞", "iuo"},

        // 泰 - has 開/合
        {"泰", "ai"},
        {"開|泰", "ai"},
        {"合|泰", "uai"},

        // 廢 - has 開/合
        {"廢", "ioi"},
        {"開|廢", "ioi"},
        {"合|廢", "iuoi"},

        // 夬 - has 開/合
        {"夬", "rai"},
        {"開|夬", "rai"},
        {"合|夬", "ruai"},

        // 佳 - has 開/合
        {"佳", "re"},
        {"開|佳", "re"},
        {"合|佳", "rue"},

        // 皆 - has 開/合
        {"皆", "rei"},
        {"開|皆", "rei"},
        {"合|皆", "ruei"},

        // 祭 - has both A/B and 開/合
        {"祭A", "iei"},
        {"祭B", "riei"},
        {"開|祭", "iei"},
        {"合|祭", "iuei"},
        {"開|祭A", "iei"},
        {"合|祭A", "iuei"},
        {"開|祭B", "riei"},
        {"合|祭B", "riuei"},

        // 齊 - has 開/合
        {"齊", "ei"},
        {"開|齊", "ei"},
        {"合|齊", "uei"},

        {"咍", "oi"},
        {"灰", "uoi"},

        // 真 - has both A/B and 開/合
        {"真", "in"},
        {"真A", "in"},
        {"真B", "rin"},
        {"開|真", "in"},
        {"合|真", "uin"},
        {"開|真A", "in"},
        {"合|真A", "uin"},
        {"開|真B", "rin"},
        {"合|真B", "ruin"},

        {"臻", "in"},
        {"諄", "uin"},

        // 質 - has both A/B and 開/合
        {"質", "it"},
        {"質A", "it"},
        {"質B", "rit"},
        {"開|質", "it"},
        {"合|質", "uit"},
        {"開|質A", "it"},
        {"合|質A", "uit"},
        {"開|質B", "rit"},
        {"合|質B", "ruit"},

        {"櫛", "it"},
        {"術", "uit"},
        
        {"痕", "on"},
        {"麧", "ot"},
        {"魂", "uon"},
        {"沒", "uot"},

        //{"欣", "iin"},
        {"殷", "iin"},
        {"迄", "iit"},

        {"文", "iun"},
        {"物", "iut"},

        {"寒", "an"},
        {"開|寒", "an"},
        {"合|寒", "uan"},
        //{"桓", "uan"},
        //{"曷", "at"},
        {"末", "at"},
        // irregular third division
        {"末!三", "iat"},
        {"開|末", "at"},
        {"合|末", "uat"},


        // 元 - has 開/合
        {"元", "ion"},
        {"開|元", "ion"},
        {"合|元", "iuon"},

        // 月 - has 開/合
        {"月", "iot"},
        {"開|月", "iot"},
        {"合|月", "iuot"},

        // 刪 - has 開/合
        {"刪", "ran"},
        {"開|刪", "ran"},
        {"合|刪", "ruan"},

        // 黠 - has 開/合
        {"黠", "ret"},
        {"開|黠", "ret"},
        {"合|黠", "ruet"},

        // 山 - has 開/合
        {"山", "ren"},
        {"開|山", "ren"},
        {"合|山", "ruen"},

        // 鎋 - has 開/合
        {"鎋", "rat"},
        // irregular occurance
        {"鎋!三", "iaet"},
        {"開|鎋", "rat"},
        {"合|鎋", "ruat"},

        // 仙 - has both A/B and 開/合
        {"仙A", "ien"},
        {"仙B", "rien"},
        {"開|仙", "ien"},
        {"合|仙", "iuen"},
        {"開|仙A", "ien"},
        {"合|仙A", "iuen"},
        {"開|仙B", "rien"},
        {"合|仙B", "riuen"},

        // 薛 - has both A/B and 開/合
        {"薛A", "iet"},
        {"薛B", "riet"},
        {"開|薛", "iet"},
        {"合|薛", "iuet"},
        {"開|薛A", "iet"},
        {"合|薛A", "iuet"},
        {"開|薛B", "riet"},
        {"合|薛B", "riuet"},

        // 先 - has 開/合
        {"先", "en"},
        {"開|先", "en"},
        {"合|先", "uen"},

        // 屑 - has 開/合
        {"屑", "et"},
        {"開|屑", "et"},
        {"合|屑", "uet"},

        {"豪", "au"},
        {"肴", "rau"},

        // 宵 - has A/B
        {"宵", "ieu"},
        {"宵A", "ieu"},
        {"宵B", "rieu"},

        {"蕭", "eu"},

        // 哥一 - has 開/合
        {"哥一", "a"},
        {"開|哥一", "a"},
        {"合|哥一", "ua"},

        // 哥三 - has 開/合
        {"哥三", "ia"},
        {"開|哥三", "ia"},
        {"合|哥三", "iua"},

        // 麻二 - has 開/合
        {"麻二", "ra"},
        {"開|麻二", "ra"},
        {"合|麻二", "rua"},

        // 麻三 - only 開
        {"麻三", "ia"},
        {"開|麻三", "ia"},

        // 唐 - has 開/合
        {"唐", "ang"},
        {"開|唐", "ang"},
        {"合|唐", "uang"},

        // 鐸 - has 開/合
        {"鐸", "ak"},
        {"開|鐸", "ak"},
        {"合|鐸", "uak"},

        // 陽 - has 開/合
        {"陽", "iang"},
        {"開|陽", "iang"},
        {"合|陽", "iuang"},

        // 藥 - has 開/合
        {"藥", "iak"},
        {"開|藥", "iak"},
        {"合|藥", "iuak"},

        // 庚二 - has 開/合
        {"庚二", "rang"},
        {"開|庚二", "rang"},
        {"合|庚二", "ruang"},
        // rare irregular occurences of 庚 after l (冷) or t (打)
        {"庚四", "aeng"},

        // 庚三 - has 開/合
        {"庚三", "riang"},
        {"開|庚三", "riang"},
        {"合|庚三", "riuang"},

        // 陌二 - has 開/合
        {"陌二", "rak"},
        {"開|陌二", "rak"},
        {"合|陌二", "ruak"},

        // 陌三 - has 開/合
        {"陌三", "riak"},
        {"開|陌三", "riak"},
        {"合|陌三", "riuak"},

        // 耕 - has 開/合
        {"耕", "reng"},
        {"開|耕", "reng"},
        {"合|耕", "rueng"},

        // 麥 - has 開/合
        {"麥", "rek"},
        {"開|麥", "rek"},
        {"合|麥", "ruek"},

        // 清 - has 開/合
        {"清", "ieng"},
        {"開|清", "ieng"},
        {"合|清", "iueng"},

        // 昔 - has 開/合
        {"昔", "iek"},
        {"開|昔", "iek"},
        {"合|昔", "iuek"},

        // 青 - has 開/合
        {"青", "eng"},
        {"開|青", "eng"},
        {"合|青", "ueng"},

        // 錫 - has 開/合
        {"錫", "ek"},
        {"開|錫", "ek"},
        {"合|錫", "uek"},

        // 登 - has 開/合
        {"登", "ong"},
        {"開|登", "ong"},
        {"合|登", "uoeng"},

        // 德 - has 開/合
        {"德", "ok"},
        {"開|德", "ok"},
        {"合|德", "uoek"},

        // 蒸 - has B/C distinctions
        {"蒸", "ing"},
        {"蒸B", "ring"},
        {"蒸C", "ing"},

        // 職B - has 開/合
        {"職B", "rik"},
        {"開|職B", "rik"},
        {"合|職B", "ruik"},
        {"職", "ik"},
        {"職C", "ik"},

        {"尤", "iou"},
        {"侯", "ou"},
        {"幽", "iu"},
        {"幽A", "iu"},
        {"幽B", "riu"},


        // 侵 - has A/B
        {"侵", "im"},
        {"侵A", "im"},
        {"侵B", "rim"},

        // 緝 - has A/B
        {"緝", "ip"},
        {"緝A", "ip"},
        {"緝B", "rip"},

        {"談", "am"},
        // irregular occurence of [ɨɑm]
        {"談!三", "iam"},
        {"盍", "ap"},
        // also irregular
        {"盍!三", "iap"},
        {"嚴", "iom"},
        {"凡", "iom"},
        {"業", "iop"},
        {"乏", "iop"},

        {"銜", "ram"},
        {"狎", "rap"},
        {"咸", "rem"},
        {"洽", "rep"},

        // 鹽 - has A/B
        {"鹽", "iem"},
        {"鹽A", "iem"},
        {"鹽B", "riem"},

        // 葉 - has A/B
        {"葉", "iep"},
        {"葉A", "iep"},
        {"葉B", "riep"},

        {"添", "em"},
        {"怗", "ep"},
        {"覃", "om"},
        {"合", "op"}
    };

    // read one line from input at a time
    std::string line;
    while (std::getline(fin, line)) {
        // skip empty lines
        if (line.empty()) continue;

        // extract first UTF-8 character
        std::string han_char = getFirstUtf8Char(line);

        // find the bracketed section to extract fanqie spellings
        // Use the actual Chinese brackets
        size_t start = findUtf8(line, "【");
        size_t end = findUtf8(line, "】");
        
        // if bracketed section was not found, skip the section
        if (start == std::string::npos || end == std::string::npos || end <= start) continue;

        // clip the section inside of the brackets
        // 【 is 3 bytes in UTF-8
        std::string inside = line.substr(start + 3, end - start - 3);
        
        // split section into different parts
        std::vector<std::string> parts = split(inside, '|');

        // store the initial, final, and tone
        std::string initial, final, tone;

        // e.g. 【端|東一|平】
        if (parts.size() == 3) {
            initial = parts[0];
            final = parts[1];
            tone = parts[2];
        }
        // e.g. 【匣|開|庚二|平】
        else if (parts.size() == 4) {
            initial = parts[0];
            final = parts[1] + "|" + parts[2]; // fuse the two
            tone = parts[3];
        }
        // skip lines with unexpected format
        else {
            std::cout << "Unexpected bracket format on line: " << inside << "\n";
            continue;
        }

        // look up mappings to convert to spelling
        std::string initial_mc = initial_map.count(initial) ? initial_map[initial] : "ERROR! INITIAL NOT FOUND";
        std::string final_mc = final_map.count(final) ? final_map[final] : "ERROR! FINAL NOT FOUND";

        if (!initial_mc.empty() && !final_mc.empty()) {
            // Combine initial and final
            std::string romanization = initial_mc + final_mc;
            
            // Apply post-processing rules
            romanization = postProcess(romanization);

            // Apply tone markers
            romanization = addToneMarkers(romanization, tone);

            fout << han_char << " " << romanization << "\n";
        }
    }

    std::cout << "Parsing complete. Results written to output.txt\n";
    return 0;
}
