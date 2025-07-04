# [Silver I] 毎日がHoliday - 29019 

[문제 링크](https://www.acmicpc.net/problem/29019) 

### 성능 요약

메모리: 2020 KB, 시간: 24 ms

### 분류

이분 탐색, 매개 변수 탐색

### 제출 일자

2025년 6월 21일 22:49:22

### 문제 설명

<p>あなたは働いたら負けだと思っている．できることなら，寝て食べてオンラインジャッジを埋めるだけの生活をしていきたい．しかし，現実は世知辛いもので，そのためにはまず先立つ資産が必要である．</p>

<p>あなたは理想の生活を以下のようにモデル化した．あなたはいくらかの初期資産を有している．毎年，生活費が <i>c</i> 必要になるため，保有している資産からちょうど <i>c</i> を年始に一括で現金化し，その現金で生活を行う．その後，現金化していない残りの全資産を 1 年間運用し，あなたの絶対に働きたくないという強い意志がもたらした天賦の資産運用能力により，必ず年末に <i>r</i> %の利率で資産を増やす．すなわち，資産を <i>M</i> だけ運用した場合，年末に資産が <i>M (1 + r / 100)</i> になる．このとき，運用後の資産が非整数となった場合，小数点以下が切り捨てられ整数となる．</p>

<p>あなたはこの理想の生活を <i>y</i> 年間続けたいと思っている．すなわち，ある年の年始から理想の生活を始め，<i>y</i> 年目の年末の時点で資産が非負であるようにしたい．理想の生活のために目標となる初期資産さえわかれば，その初期資産を盾に高らかに辞表を叩きつける未来のために，一時負けを受け入れ労働に甘んじてやらないこともない．そこでまず，モデル化された理想の生活を <i>y</i> 年間続けるために必要な初期資産として最小の整数を求めるプログラムを書くことにした．</p>

### 입력 

 <p>入力は複数のデータセットからなる． 各データセットは次の形式で表される．</p>

<blockquote><i>y</i> <i>c</i> <i>r</i></blockquote>

<p><i>y</i> は理想の生活を行う年数であり，<i>1</i> 以上 <i>100,000</i> 以下の整数である．<i>c</i> は <i>1</i> 年分の生活費であり，<i>1</i> 以上 <i>10<sup>9</sup></i> 以下の整数である．<i>r</i> は <i>1</i> 年間の資産運用による利率であり，<i>1</i> 以上 <i>100</i> 以下の整数である．</p>

<p>入力の終わりは 3 つのゼロからなる行で表される． 入力に含まれるデータセットは <i>50</i> 個以内である．</p>

### 출력 

 <p>各データセットに対して，年始に資産が <i>c</i> 減り，年末に残りの資産が <i>r</i> %増える生活を <i>y</i> 年間行うために必要となる最小の初期資産を，整数で <i>1</i> 行に出力せよ．</p>

