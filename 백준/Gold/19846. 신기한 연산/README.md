# [Gold I] 신기한 연산 - 19846 

[문제 링크](https://www.acmicpc.net/problem/19846) 

### 성능 요약

메모리: 2020 KB, 시간: 16 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2025년 3월 23일 11:50:53

### 문제 설명

<p>재현이는 문제를 풀다가 신기한 연산을 발견했다. 이 연산을 사용하면 홀수 번 등장하는 원소가 <strong>단 하나</strong> 있는 원소들의 나열에서 그 원소를 빠르게 찾을 수 있다. 예를 들어 수열 (1, 3, 2, 1, 2)에 이 연산을 적용하면 유일하게 한 번만 등장하는 수인 3을 얻을 수 있다.</p>

<p>재현이는 이 연산에 큰 감명을 받고, 이 연산을 사용하는 문제를 반드시 출제하기로 결심했다. 그리고 마침내 출제할 기회가 주어지자, 다음과 같은 문제를 야심차게 내놓았다.</p>

<blockquote>
<p><em>N</em>종류의 알파벳 소문자로 이루어진 <em>M</em>글자의 문자열과 <em>Q</em>개의 구간들이 주어진다. 문자열에서 각각의 구간에 해당하는 부분 문자열을 뽑았을 때, 각 부분 문자열에는 <em>N</em>종류의 알파벳이 <strong>전부</strong> 등장하며 그중 홀수 번 등장하는 알파벳이 <strong>단 한 종류</strong> 있음이 보장된다.</p>

<p>이때 각 구간에 대해 해당하는 부분 문자열에서 홀수 번 등장하는 알파벳을 찾는 프로그램을 작성하라.</p>
</blockquote>

<p>문제의 데이터를 준비하던 재현이는 구간들은 쉽게 만들 수 있었으나, 이 구간들에 대해 위의 조건을 만족하는 문자열을 도저히 만들 수 없었다. 그래서 재현이는 데이터를 만드는 작업을 또다른 출제진인 당신에게 맡기기로 했다. 재현이를 도와서 데이터를 만들어 주자.</p>

### 입력 

 <p>첫 줄에 세 개의 정수 <span style="font-style: italic;">N</span>, <span style="font-style: italic;">M</span>, <span style="font-style: italic;">Q</span>가 주어진다. <span style="font-style: italic;">N</span>은 사용해야 하는 알파벳의 종류 수, <span style="font-style: italic;">M</span>은 만들고자 하는 문자열의 길이, <span style="font-style: italic;">Q</span>는 재현이가 만들어 놓은 구간들의 개수를 의미한다.</p>

<p>이후 <span style="font-style: italic;">Q</span>개의 줄에 걸쳐 구간들이 주어진다. (<span style="font-style: italic;">i</span> + 1)번째 줄에는 두 개의 정수 <span style="font-style: italic;">s</span><sub><span style="font-style: italic;">i</span></sub>와 <span style="font-style: italic;">e</span><sub><span style="font-style: italic;">i</span></sub>가 공백을 사이에 두고 주어지며, 각각 구간의 시작 위치와 끝 위치를 의미한다. 각 구간의 너비는 2<span style="font-style: italic;">N</span> − 1 이상의 홀수이며, 같은 구간이 여러 번 주어지지 않음이 보장된다.</p>

### 출력 

 <p>첫 줄에 알파벳 소문자만으로 이루어진 <span style="font-style: italic;">M</span>글자의 문자열을 출력한다. 이 문자열은 정확히 <span style="font-style: italic;">N</span>종류의 알파벳으로 이루어져 있어야 하며, 입력으로 주어진 모든 구간에 대해 재현이가 출제하려는 문제의 조건을 만족해야 한다.</p>

<p>이러한 문자열이 존재하는 경우만이 입력으로 주어짐이 보장된다.</p>

