# rime-trjung
Custom [Rime](https://github.com/rime) input method using the custom RS romanization scheme.

The parser program converts character data into a dictionary file for RIME.

Built on top of [rime-trjuwngkux](https://github.com/shinzoqchiuq/rime-trjuwngkux) using RIME's regex engine

The scheme is documented below

- **B** = Baxter Notation  
- **ZZ** = Zhengzhang Shangfang reconstruction  
- **RSR** = RS romanization  
- **RSRC** = RS reconstruction  

---

## 脣音 / Bilabial

| #  | Name     | B   | RSR | ZZ  | RSRC |
|----|----------|-----|-----|-----|------|
| 1  | 帮/非/幫 | p   | p   | p   | p    |
| 2  | 滂/敷   | ph  | ph  | pʰ  | pʰ   |
| 3  | 並/奉/并 | b   | b   | b   | b    |
| 4  | 明/微   | m   | m   | m   | m    |

---

## 舌頭音 / Alveolar

| #  | Name | B  | RSR | ZZ | RSRC |
|----|------|----|-----|----|------|
| 5  | 端   | t  | t   | t  | t    |
| 6  | 透   | th | th  | tʰ | tʰ   |
| 7  | 定   | d  | d   | d  | d    |
| 8  | 泥   | n  | n   | n  | n    |

---

## 舌上音 / Retroflex

| #  | Name   | B   | RSR | ZZ  | RSRC |
|----|--------|-----|-----|-----|------|
| 9  | 知     | tr  | tr  | ʈ   | ʈ    |
| 10 | 徹     | trh | thr | ʈʰ  | ʈʰ   |
| 11 | 澄     | dr  | dr  | ɖ   | ɖ    |
| 12 | 孃/娘 | nr  | nr  | ɳ   | ɳ    |

---

## 齒頭音 / Dental

| #  | Name     | B   | RSR | ZZ   | RSRC |
|----|----------|-----|-----|------|------|
| 13 | 精       | ts  | ts  | t͡s  | t͡s  |
| 14 | 清       | tsh | tsh | t͡sʰ | t͡sʰ |
| 15 | 从/從   | dz  | dz  | d͡z  | d͡z  |
| 16 | 心       | s   | s   | s    | s    |
| 17 | 邪       | z   | z   | z    | z    |

---

## 正齒音 / Retroflex (Affricates & Fricatives)

| #  | Name     | B    | RSR  | ZZ   | RSRC |
|----|----------|------|------|------|------|
| 18 | 庄/莊   | tsr  | tsr  | t͡ʃ  | ʈ͡ʂ  |
| 19 | 初       | tsrh | tshr | t͡ʃʰ | ʈ͡ʂʰ |
| 20 | 崇       | dzr  | dzr  | d͡ʒ  | ɖ͡ʐ  |
| 21 | 生       | sr   | sr   | ʃ    | ʂ    |
| 22 | 俟       | zr   | zr   | ʒ    | ʐ    |

---

## 正齒音 / Post-alveolar

| #  | Name         | B    | RSR  | ZZ   | RSRC |
|----|--------------|------|------|------|------|
| 23 | 章           | tsy  | tsy  | t͡ɕ  | t͡ɕ  |
| 24 | 昌           | tsyh | tshy | t͡ɕʰ | t͡ɕʰ |
| 25 | 禅/禪/常    | dzy  | dzy  | d͡ʑ  | d͡ʑ  |
| 26 | 書/书       | sy   | sy   | ɕ    | ɕ    |
| 27 | 船           | zy   | zy   | ʑ    | ʑ    |

---

## 牙音 / Velar

| #  | Name   | B  | RSR | ZZ | RSRC |
|----|--------|----|-----|----|------|
| 28 | 見/见 | k  | k   | k  | k    |
| 29 | 溪/谿 | kh | kh  | kʰ | kʰ   |
| 30 | 群/羣 | g  | g   | ɡ  | ɡ    |
| 31 | 疑     | ng | ng  | ŋ  | ŋ    |

---

## 喉音 / Glottal

| #  | Name       | B  | RSR    | ZZ  | RSRC |
|----|------------|----|--------|-----|------|
| 32 | 曉/晓     | x  | h      | h   | h    |
| 33 | 匣         | h  | gh     | ɦ   | ɦ    |
| 34 | 影         | ‘  | ‘ / ∅ | ʔ   | ʔ    |
| 35 | 云/雲/于 | h  | gh     | ɦ   | ɦ    |

---

## Other

| #  | Name   | B  | RSR | ZZ  | RSRC |
|----|--------|----|-----|-----|------|
| 36 | 以     | y  | y   | j   | j    |
| 37 | 来/來 | l  | l   | l   | l    |
| 38 | 日     | ny | ny  | ȵ   | ȵ    |

---

---

## 韻母 / Rhymes

<details>
<summary>通攝</summary>

| #  | Name | B    | RSR  | ZZ   | RSRC       |
|----|------|------|------|------|------------|
| 1  | 東一 | uwng | ung  | uŋ   | uŋ         |
| 2  | 東三 | juwng| jung | ɨuŋ  | iuŋ        |
| 3  | 屋一 | uwk  | uk   | uk̚  | uk̚        |
| 4  | 屋三 | juwk | juk  | ɨuk̚ | iuk̚       |
| 5  | 冬  | owng | uong | uoŋ  | oŋ~uoŋ     |
| 6  | 沃  | owk  | uok  | uok̚ | ok̚~uok̚   |
| 7  | 鍾  | jowng| juong| ɨoŋ  | ioŋ        |
| 8  | 燭  | jowk | juok | ɨok̚ | iok̚       |

</details>

<details>
<summary>江攝</summary>

| #  | Name | B     | RSR | ZZ   | RSRC         |
|----|------|-------|-----|------|--------------|
| 9  | 江  | aewng | rong| ˠʌŋ  | ɣʌŋ~ɣɔŋ     |
| 10 | 覺  | aewk  | rok | ˠʌk̚ | ɣʌŋ~ɣɔk̚    |

</details>

<details>
<summary>止攝</summary>

| #  | Name | B    | RSR | ZZ    | RSRC |
|----|------|------|-----|-------|------|
| 11 | 支三開 | jie  | ie  | iᴇ    | ie   |
| 12 | 支三合 | jwie | wie | iuᴇ   | ye   |
| 13 | 支重鈕三開 | je | rie | ˠiᴇ   | ɣie  |
| 14 | 支重鈕三合 | jwe| rwie| ˠiuᴇ | ɣye  |
| 15 | 脂重鈕四開 / 脂三開 | jij | i   | iɪ   | i    |
| 16 | 脂重鈕四合 / 脂三合 | jwij| wi  | iuɪ  | yi   |
| 17 | 脂重鈕三開 | ij   | ri  | ˠiɪ  | ɣi   |
| 18 | 脂重鈕三合 | wij  | rwi | ˠiuɪ | ɣyi  |
| 19 | 之   | i    | ii  | ɨ    | ɨ    |
| 20 | 微開 | jɨj  | iij | ɨi   | ɨi   |
| 21 | 微合 | jwɨj | wiij| ʉi   | wɨi~ʉɨi~ʉi |

</details>

<details>
<summary>遇攝</summary>

| #  | Name | B   | RSR | ZZ  | RSRC     |
|----|------|-----|-----|-----|----------|
| 22 | 魚  | jo  | jo  | ɨʌ | iʌ~iɔ    |
| 23 | 模  | u   | uo  | uo  | uo~o     |
| 24 | 虞  | ju  | juo | ɨo  | io       |

</details>

<details>
<summary>蟹攝</summary>

| #  | Name | B    | RSR | ZZ    | RSRC |
|----|------|------|-----|-------|------|
| 25 | 泰開 | aj   | aj  | ɑi    | ɑi   |
| 26 | 泰合 | waj  | waj | uɑi   | uɑi  |
| 27 | 廢開 | joj  | joj | ɨɐi   | iɐi  |
| 28 | 廢合 | jwoj | jwoj| ʉɐi   | yɐi  |
| 29 | 夬開 | aej  | raj | ˠai   | ɣai  |
| 30 | 夬合 | waej | rwaj| ˠuai  | ɣuai |
| 31 | 佳開 | ea   | re  | ˠɛ    | ɣɛ   |
| 32 | 佳合 | wea  | rwe | ˠuɛ   | ɣuɛ  |
| 33 | 皆開 | eaj  | rej | ˠɛi   | ɣɛi  |
| 34 | 皆合 | weaj | rwej| ˠuɛi  | ɣuɛi |
| 35 | 祭重鈕四開 / 祭三開 | jiej | jej | iᴇi | iei |
| 36 | 祭三合 / 祭重鈕四合 | jwiej| jwej| iuᴇi | yei |
| 37 | 祭重鈕三開 | jej   | rjej | ˠiᴇi | ɣiei |
| 38 | 祭重鈕三合 | jwej  | rjwej| ˠiuᴇi| ɣyei |
| 39 | 齊開 | ej   | ej  | ei    | ei   |
| 40 | 齊合 | wej  | wej | wei   | wei  |
| 41 | 咍  | oj   | oj  | ʌi    | ʌi   |
| 42 | 灰  | woj  | woj | uʌi   | uʌi~uɔi |

</details>

<details>
<summary>臻攝</summary>

| #  | Name | B   | RSR | ZZ   | RSRC        |
|----|------|-----|-----|-----|-------------|
| 43 | 真三 / 真重鈕四 | jin | in  | iɪn | in          |
| 44 | 真開 | in  | rin | ˠiɪn | ɣin        |
| 45 | 真合 | win | rwin| ˠiuɪn| ɣyin       |
| 46 | 臻   | in  | in  | ɪn   | ɪn~in      |
| 47 | 諄   | jwin| win | iuɪn | yɪn~yin    |
| 48 | 質重鈕四 / 質三 | jit | it  | iɪt̚ | it̚~iɪt̚ |
| 49 | 質開 | it  | rit | ˠiɪt̚| ɣit̚~ɣiɪt̚|
| 50 | 質合 | wit | rwit| ˠiuɪt̚| ɣyit̚~ɣyiɪt̚ |
| 51 | 櫛   | it  | it  | ɪt̚ | ɪt̚~it̚~iɪt̚ |
| 52 | 術   | jwit| wit | iuɪt̚| yɪt̚~yit̚~yiɪt̚ |
| 53 | 痕   | on  | on  | ən   | ən         |
| 54 | 麧   | ot  | ot  | ət̚  | ət̚        |
| 55 | 魂   | won | won | uən  | uən        |
| 56 | 沒   | wot | wot | uət̚ | uət̚       |
| 57 | 欣   | jɨn | iin | ɨn   | ɨn         |
| 58 | 迄   | jɨt | iit | ɨt̚  | ɨt̚        |
| 59 | 文   | jun | jun | ɨun  | ɨun~ɨuən  |
| 60 | 物   | jut | jut | ɨut̚ | ɨut̚~ɨuət̚ |

</details>

<details>
<summary>山攝</summary>

| #  | Name | B    | RSR | ZZ   | RSRC       |
|----|------|------|-----|-----|------------|
| 61 | 寒  | an   | an  | ɑn  | ɑn         |
| 62 | 桓  | wan  | wan | uɑn | uɑn        |
| 63 | 曷  | at   | at  | ɑt̚ | ɑt̚        |
| 64 | 末  | wat  | wat | uɑt̚| uɑt̚       |
| 65 | 元開 | jon  | jon | ɨɐn| iɐn        |
| 66 | 元合 | jwon | jwon| ʉɐn| yɐn        |
| 67 | 月開 | jot  | jot | ɨɐt̚| iɐt̚       |
| 68 | 月合 | jwot | jwot| ʉɐt̚| yɐt̚       |
| 69 | 刪開 | aen  | ran | ˠan | ɣan        |
| 70 | 刪合 | waen | rwan| ˠuan| ɣuan       |
| 71 | 黠開 | aet  | rat | ˠat̚| ɣat̚       |
| 72 | 黠合 | waet | rwat| ˠuat̚| ɣuat̚     |
| 73 | 山開 | ean  | ren | ˠɛn | ɣɛn        |
| 74 | 山合 | wean | rwen| ˠuɛn| ɣuɛn       |
| 75 | 鎋開 | eat  | ret | ˠɛt̚| ɣɛt̚       |
| 76 | 鎋合 | weat | rwet| ˠuɛt̚| ɣuɛt̚     |
| 77 | 仙三開 | jien | jen | iᴇn | ien     |
| 78 | 仙三合 | jwien| jwen| iuᴇn| yen      |
| 79 | 仙重鈕三開 | jen  | rjen| ˠiᴇn| ɣien |
| 80 | 仙重鈕三合 | jwen | rjwen| ˠiuᴇn| ɣyen |
| 81 | 薛三開 | jiet | jet | iᴇt̚| iet̚     |
| 82 | 薛三合 | jwiet| jwet| iuᴇt̚| yet̚    |
| 83 | 薛重鈕三開 | jet  | rjet| ˠiᴇt̚| ɣiet̚|
| 84 | 薛重鈕三合 | jwet | rjwet| ˠiuᴇt̚| ɣyet̚|
| 85 | 先開 | en   | en  | en  | en         |
| 86 | 先合 | wen  | wen | wen | wen        |
| 87 | 屑開 | et   | et  | et̚ | et̚        |
| 88 | 屑合 | wet  | wet | wet̚| wet̚      |

</details>

<details>
<summary>效攝</summary>

| #  | Name | B    | RSR | ZZ   | RSRC |
|----|------|------|-----|------|------|
| 89 | 豪  | aw   | aw  | ɑu   | ɑu   |
| 90 | 肴  | aew  | raw | ˠau  | ɣau  |
| 91 | 宵三 / 宵重鈕四 | jiew | jew | iᴇu | iɛu |
| 92 | 宵重鈕三 | jew  | rjew| ˠiᴇu | ɣiɛu |
| 93 | 蕭  | ew   | ew  | eu   | eu   |

</details>

<details>
<summary>果攝</summary>

| #  | Name | B   | RSR | ZZ  | RSRC |
|----|------|-----|-----|-----|------|
| 94 | 歌  | a   | a   | ɑ   | ɑ    |
| 95 | 戈一合 | wa  | wa  | uɑ  | uɑ   |
| 96 | 戈三開 | ja  | ja  | ɨɑ  | iɑ   |
| 97 | 戈三合 | jwa | jwa | ɨuɑ | yɑ   |

</details>

<details>
<summary>假攝</summary>

| #  | Name | B   | RSR | ZZ  | RSRC |
|----|------|-----|-----|-----|------|
| 98 | 麻二開 | ae  | ra  | ˠa  | ɣa  |
| 99 | 麻二合 | wae | rwa | ˠua | ɣua |
| 100| 麻三開 | jae | ja  | ia  | ia  |

</details>

<details>
<summary>宕攝</summary>

| #   | Name | B    | RSR | ZZ   | RSRC         |
|-----|------|------|-----|------|--------------|
| 101 | 唐開 | ang  | ang | ɑŋ  | ɑŋ           |
| 102 | 唐合 | wang | wang| uɑŋ | uɑŋ          |
| 103 | 鐸開 | ak   | ak  | ɑk̚ | ɑk̚          |
| 104 | 鐸合 | wak  | wak | uɑk̚| uɑk̚         |
| 105 | 陽開 | jang | jang| ɨɐŋ| iɑŋ~iɐŋ     |
| 106 | 陽合 | jwang| jwang| ʉɐŋ| yɑŋ~yɐŋ     |
| 107 | 藥開 | jak  | jak | ɨɐk̚| iɑk̚~iɐk̚   |
| 108 | 藥合 | jwak | jwak| ʉɐk̚| yɑk̚~yɐk̚   |

</details>

<details>
<summary>梗攝</summary>

| #   | Name | B     | RSR | ZZ    | RSRC         |
|-----|------|-------|-----|-------|--------------|
| 109 | 庚二開 | aeng  | rang | ˠæŋ  | ɣæŋ         |
| 110 | 庚二合 | waeng | rwang| ˠwæŋ | ɣuæŋ        |
| 111 | 庚三開 / 庚重鈕三開 | jaeng | rjang| ˠiæŋ | ɣiæŋ |
| 112 | 庚重鈕三合 / 庚三合 | jwaeng| rjwang| ˠwiæŋ | ɣyæŋ |
| 113 | 陌二開 | aek  | rak  | ˠæk̚ | ɣæk̚        |
| 114 | 陌二合 | waek | rwak | ˠwæk̚| ɣuæk̚       |
| 115 | 陌三開 | jæk  | rjak | ˠiæk̚| ɣiæk̚       |
| 116 | 陌三合 | jwæk | rjwak| ˠwiæk̚| ɣyæk̚     |
| 117 | 耕開 | eang | reng | ˠɛŋ  | ɣɛŋ         |
| 118 | 耕合 | weang| rweng| ˠwɛŋ | ɣuɛŋ        |
| 119 | 麥開 | eak  | rek  | ˠɛk̚ | ɣɛk̚        |
| 120 | 麥合 | weak | rwek | ˠwɛk̚| ɣuɛk̚       |
| 121 | 清開 | jieng| jeng | iᴇŋ  | ieŋ         |
| 122 | 清合 | jwieng| jweng| wiᴇŋ | yeŋ         |
| 123 | 昔開 | jiek | jek  | iᴇk̚ | iek̚        |
| 124 | 昔合 | jwiek| jwek | wiᴇk̚| yek̚        |
| 125 | 青開 | eng  | eng  | eŋ   | eŋ          |
| 126 | 青合 | weng | weng | weŋ   | weŋ   |
| 127 | 錫開 | ek   | ek   | ek̚  | ek̚  |
| 128 | 錫合 | wek  | wek  | wek̚ | wek̚ |
| 129 | 登開 | ong  | ong  | əŋ   | əŋ   |
| 130 | 登合 | wong | wong | wəŋ  | wəŋ  |
| 131 | 德開 | ok   | ok   | ək̚  | ək̚  |
| 132 | 德合 | wok  | wok  | wək̚ | wək̚ |

</details>

<details>
<summary>曾攝</summary>

| #   | Name | B   | RSR | ZZ   | RSRC         |
|-----|------|-----|-----|------|--------------|
| 133 | 蒸  | ing | ing | ɨŋ   | ɨŋ~iəŋ      |
| 134 | 職開 | ik  | ik  | ɨk̚  | ɨk̚~iək̚    |
| 135 | 職合 | wik | wik | wɨk̚ | uɨk̚~uɨək̚ |

</details>

<details>
<summary>流攝</summary>

| #   | Name | B   | RSR | ZZ   | RSRC       |
|-----|------|-----|-----|------|------------|
| 136 | 尤  | juw | jow | ɨu   | ɨu~iəu     |
| 137 | 侯  | uw  | ow  | əu   | əu         |
| 138 | 幽  | jiw | iw  | iɪu  | iu         |

</details>

<details>
<summary>深攝</summary>

| #   | Name | B   | RSR | ZZ    | RSRC |
|-----|------|-----|-----|-------|------|
| 139 | 侵三 | jim | im  | iɪm   | im   |
| 140 | 侵重鈕三 | im | rim | ˠiɪm | ɣim  |
| 141 | 緝三 | jip | ip  | iɪp̚  | ip̚  |
| 142 | 緝重鈕三 | ip | rip | ˠiɪp̚| ɣip̚ |

</details>

<details>
<summary>咸攝</summary>

| #   | Name | B    | RSR | ZZ    | RSRC |
|-----|------|------|-----|-------|------|
| 143 | 談  | am   | am  | ɑm    | ɑm   |
| 144 | 盍  | ap   | ap  | ɑp̚   | ɑp̚  |
| 145 | 嚴  | jæm  | jom | ɨɐm   | iɐm  |
| 146 | 凡  | jom  | jom | ɨɐm   | iɐm  |
| 147 | 業  | jæp  | jop | ɨɐp̚  | iɐp̚ |
| 148 | 乏  | jop  | jop | ɨɐp̚  | iɐp̚ |
| 149 | 銜  | æm   | ram | ˠam   | ɣam  |
| 150 | 狎  | æp   | rap | ˠap̚  | ɣap̚ |
| 151 | 咸  | ɛm   | rem | ˠɛm   | ɣɛm  |
| 152 | 洽  | ɛp   | rep | ˠɛp̚  | ɣɛp̚ |
| 153 | 鹽三 | jiem | jem | iᴇm  | iɛm  |
| 154 | 鹽重鈕三 | jem | rjem| ˠiᴇm | ɣiɛm |
| 155 | 葉三 | jiep | jep | iᴇp̚ | iɛp̚ |
| 156 | 葉重鈕三 | jep | rjep| ˠiᴇp̚| ɣiɛp̚ |
| 157 | 添  | em   | em  | em    | em   |
| 158 | 貼 / 怗 | ep | ep  | ep̚   | ep̚  |
| 159 | 覃  | om   | om  | ʌm    | ʌm   |
| 160 | 合  | op   | op  | ʌp̚   | ʌp̚  |

</details>
