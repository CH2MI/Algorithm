# [Platinum II] 유산 - 24235 

[문제 링크](https://www.acmicpc.net/problem/24235) 

### 성능 요약

메모리: 41484 KB, 시간: 556 ms

### 분류

이분 탐색, 볼록 껍질, 기하학, 매개 변수 탐색, 다각형의 넓이

### 제출 일자

2024년 12월 24일 12:18:29

### 문제 설명

<p>조상때부터 대대로 물려받던 땅이 있다. 땅이 매우 크기 때문에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개 위치를 좌표평면 위에 점으로 표시를 해놓았다. 땅은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 점을 모두 포함하는 가장 작은 볼록다각형이다.</p>

<p>이 땅을 두 명한테 나눠주려고 한다. 나눠주는 땅의 넓이가 같도록 해야 싸움이 일어나지 않을 것이기 때문에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$y$</span></mjx-container>축이랑 평행한 직선 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi><mo>=</mo><mi>a</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x = a$</span></mjx-container>를 그어 나눠지는 두 땅의 넓이가 같도록 하려고 한다.</p>

<p>[그림 1]처럼 좌표평면에 9개 점이 존재한다고 가정해보자.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5724fbdf-9ef9-4726-8f99-c786b3867874/-/preview/" style="width: 596px; height: 500px;"></p>

<p style="text-align: center;">[그림 1] 9개의 점을 좌표평면에 표시</p>

<p>땅을 표시하는 좌표평면 정보에서 땅은 9개의 점을 모두 포함하는 가장 작은 볼록다각형이기 때문에 [그림 2]와 같다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6ccc2e35-3399-4d2a-a70d-799734cfccaf/-/preview/" style="width: 596px; height: 500px;"></p>

<p style="text-align: center;">[그림 2] 좌표평면에 땅에 해당하는 부분 표시</p>

<p>두 명이 이 땅을 넓이가 같도록 나눠야 하기 때문에 [그림 3]처럼 직선을 그어 두 땅의 넓이가 같도록 구분하면 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/61b33929-d1e9-4bfd-af3d-59b483041904/-/preview/" style="width: 596px; height: 500px;"></p>

<p style="text-align: center;">[그림 3] 두 땅의 넓이가 같도록 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3D"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi><mo>=</mo><mi>a</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x = a$</span></mjx-container> 직선으로 구분</p>

<p>땅의 정보가 주어졌을 때 같은 면적의 땅을 나눌 수 있도록 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>a</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$a$</span></mjx-container>의 값을 찾아주자.</p>

### 입력 

 <p>첫째 줄에 깃발의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>500</mn><mo>,</mo><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3 ≤ N ≤ 500,000$</span></mjx-container>)이 주어진다. </p>

<p>둘째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 깃발이 위치한 좌표 <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>x</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$x$</span></mjx-container>, <mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>y</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$y$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D465 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D466 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-texatom size="s" texclass="ORD"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-texatom></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>−</mo><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mn>9</mn></mrow></msup><mo>≤</mo><mi>x</mi><mo>,</mo><mi>y</mi><mo>≤</mo><msup><mn>10</mn><mrow data-mjx-texclass="ORD"><mn>9</mn></mrow></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$-10^{9} ≤ x, y ≤ 10^{9}$</span></mjx-container>)가 공백으로 구분되어 주어진다. 중복된 좌표가 없음과 볼록다각형의 넓이가 항상 0보다 큰 것을 보장한다.</p>

<p>입력으로 주어지는 모든 값은 정수이다.</p>

### 출력 

 <p><mjx-container class="MathJax" jax="CHTML" style="font-size: 99.9%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>a</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$a$</span></mjx-container>의 값을 출력한다. 모범 답안과의 절대/상대 오차가 10<sup>-3</sup> 이하인 경우 정답으로 인정된다.</p>

