# 문병로 교수님 자료구조 과제 6 - Subway

## Project explanation

이 프로젝트는 역과 역간 거리, 환승 정보, 노선 등을 입력받아 자료구조를 형성한 뒤에, 두 역에 대한 최단 시간, 최단 환승 경로를 계산하는 프로젝트입니다.

**Example data set**

* `seoul.txt` 참조, 환승역은 서로 다른 역 코드명에 같은 이름을 가지고 있습니다. 경로는 같은 역이나 환승역으로 이어지지 않는 양의 정수입니다.

## Program explanation

* Subway.java : 지하철(그래프) 환승을 고려한 최단거리를 찾는 프로그램입니다.
* generator.cpp : Subway 프로그램을 검증하기 위해 테스트 데이터 셋을 생성하는 프로그램입니다.
    `./gen {{outfile name}} {{total nodes}} {{total names}} {{max weight}}`
    `./gen out.txt 3000 1000 5`
* generator2.cpp : Subway 프로그램을 검증하기 위해 인스트럭션을 생성하는 프로그램입니다.
    `./inst {{outfile name}} {{number of instructions}} {{number of total names}}`
    `./inst inst.txt 50 1000`

## Program Compilation & Run

* For Linux(bash)
    `javac *.java`
    `g++ -o gen -std=gnu++11 generator.cpp`
    `./java Subway {{subway data}} <{{instruction file}}> {{output file}}`
    `./gen out.txt 3000 1000 5`
* For Windows(cmd)
    `javac *.java -encoding UTF8`
    `g++ -o gen.exe -std=gnu++11 generator.cpp`
    `gen.exe out.txt 3000 1000 5`
    `java -classpath . Subway {{subway data}} <{{instruction file}}> {{output file}}`

## Example output

`흑석 동작 구반포 신반포 [고속터미널] 교대 남부터미널 [양재] 양재시민의숲 청계산입구 판교 [정자] 수내 서현`
`53`

