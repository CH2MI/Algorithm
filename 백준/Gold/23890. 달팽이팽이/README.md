# [Gold IV] 달팽이팽이 - 23890 

[문제 링크](https://www.acmicpc.net/problem/23890) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

기하학, 수학

### 제출 일자

2025년 5월 31일 10:26:55

### 문제 설명

<p>빅토리아 아일랜드의 모험가인 당신은 달팽이만 골라 사냥하는 것으로 유명하다. 그러던 어느 날, 당신은 리스 항구 어딘가에서 거대하고 강력한 장수 달팽이 '마노'가 나온다는 소문을 듣게 되었다. 더 크고 강한 달팽이를 원하고 있던 당신은 마노를 찾기 위해 리스 항구 구석구석을 뒤지기 시작했고, 한참 동안 돌아다닌 끝에 마침내 마노를 발견할 수 있었다. 당신은 명성에 걸맞은 마노의 풍채에 잠시 압도되었지만, 스킬 '달팽이의 약점'을 갖고 있었기에 금세 마노 사냥에 성공할 수 있었다. 그러자, 마노는 이해할 수 없는 말 몇 마디와 무지개색 달팽이 등껍질을 남기고 사라졌다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/60d92a29-0b7e-40a1-9514-bae3b12a5fe6/-/preview/" style="width: 300px; height: 180px;"></p>

<p>당신은 뭔가에 홀린 듯 무지개색 달팽이 등껍질을 사용했고, 그 순간 달팽이로 변하고 말았다! 다행히도 얼마 지나지 않아 돌아올 수 있었지만, 당신은 무의식중에 바라던 소원이 바로 달팽이가 되는 것이었다는 사실을 깨달을 수 있었다. 아쉽게도 세상에 단 하나뿐인 무지개색 달팽이 등껍질은 더는 얻을 수 없었고, 그 뜻은 당신이 다시 달팽이가 될 수는 없다는 것을 의미했다. 당신은 달팽이가 되는 대신, 그간 잡은 달팽이들을 기리기 위해 그동안 모은 달팽이 등껍질을 의미 있게 사용하기로 결심했다.</p>

<p>달팽이 껍질의 활용 방법에 대해 고민하던 당신은 엄청난 아이디어를 떠올렸다! 그것은 바로 달팽이 껍질로 장난감 팽이를 만드는 것이었다. 당신은 이를 “달팽이팽이”라 이름 붙이고 만들기 시작했다. 달팽이팽이는 판과 축을 조립해서 만들어지며, 달팽이팽이의 판은 다음 그림과 같이 표현된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/aa418333-855e-486b-943b-a82a2cd425aa/-/preview/" style="width: 300px; height: 302px;"></p>

<p>즉, 좌표평면 상에서 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: 0.363em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-msup space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: 0.363em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: 0.363em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mi>x</mi><mn>2</mn></msup><mo>+</mo><msup><mi>y</mi><mn>2</mn></msup><mo>≤</mo><msup><mi>R</mi><mn>2</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x^2+y^2 ≤ R^2$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0 ≤ x$</span></mjx-container> 인 영역이다. 각각의 달팽이팽이에는 <strong>전투력</strong>이라는 척도가 존재하는데, 이는 축을 중심으로 판을 한 바퀴 돌렸을 때에 생기는 자취의 넓이로 정의된다. <strong>전투력</strong>은 축의 위치에 따라 달라지며, 전투력이 높은 팽이일수록 잘 팔리기 때문에 당신은 이를 최대화하는 축의 위치를 찾으려 한다. 축은 판의 경계가 아닌 정확히 내부에 위치해야 하며, 공정 과정의 편리함을 위해 축의 좌표는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mi>x</mi><mo>,</mo><mi>y</mi><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(x, y)$</span></mjx-container> 모두가 정수여야 한다. 판의 반지름 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>R</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$R$</span></mjx-container>이 주어질 때, 전투력을 최대화하는 축의 위치를 찾아라.</p>

### 입력 

 <p>첫째 줄에 판의 반지름을 의미하는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D445 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>R</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$R$</span></mjx-container>이 입력된다.</p>

### 출력 

 <p>전투력을 최대화하는 축 좌표를 출력한다. 만약 가능한 답이 여럿일 경우 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container>좌표가 가장 큰 답을, <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container>좌표가 같은 답이 여럿일 경우 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$y$</span></mjx-container>좌표가 가장 큰 답을 출력한다.</p>

