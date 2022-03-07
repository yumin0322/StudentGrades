
프로그램 목표 : 학생 수를 입력받고(성적과 학생정보는 자동입력)
               성적을 [출력/검색/삭제/수정/정렬/삽입]

[1]타입 잡아주기, 메뉴선택
1-1) “학생정보-이름,학번,성별 || 성적국어 수학 영어 세과목과 총점 및 평균과 등급”
의 타입과 주소(번지)를 구조체로 잡아주고,
포인트 변수를 이용하여 함수를 잡아 목표 수행

1-2) 원하는 알고리즘을 수행할 수 있게  메뉴를 보여주고 선택하게 한다.
//반복문, switch case문을 이용

[2]학생정보 입력
등록할 학생 수 입력받기(최대 학생수 100명) = total_count

[3]학생정보, 성적 자동 입력/ 출력
3-1)학생 정보, 성적을 랜덤 입력 //rand()%(max-min+1)+min;
<기준>

학생
성적
이름 : 세글자
korean, math, english
1점 ~ 100점

학번 : 10000~9999 (네자리)
성별 : 0(여), 1(남)


3-2)출력을 원할 경우 이 랜덤값을 출력하게 한다.

[4]성적 검색
4-1)검색할 학생의 이름을 입력받아 입력된 성적 중,
해당되는 정보를 불러와 출력
// strnicmp(두개의 문자열을 대소비교, 값이 0이면 해당되는 정보)

4-2)없는 정보를 입력할 경우, 이를 알리는 문구 출력

[5]성적 삭제
5-1)삭제할 학생의 이름을 입력받아 입력된 성적 중,
해당되는 정보를 불러온다.//[4]의 방식과 동일

5-2) 불러온 정보를 모두 초기화 시킨다.(각 타입에 맞는 디폴트값)

5-3)없는 정보를 입력할 경우, 이를 알리는 문구 출력

[6]성적 수정
6-1)수정할 학생의 이름을 입력받아 입력된 성적 중,
해당되는 정보를 불러온다.//[4]의 방식과 동일

6-2)불러온 정보의 “주소값”에 수정값을 입력받는다.
//printf,scanf

6-3)없는 정보를 입력할 경우, 이를 알리는 문구 출력

[7]성적 정렬(오름차순/내림차순)
7-1) 원본을 복사한다.
//memcpy :　구조체 배열을 복사(메모리 복사)

7-2) 어떤 순열(오름차순or내림차순)로 정렬할 것인지 선택하게끔 입력값 설정

7-3) 복사한 값으로 정렬 수행
//반복문, if문, memcpy연산자이용

7-4) 정렬한 값을 기존 [3]에서 만들어 놓은 출력 함수를 이용하여 출력

[8]성적 삽입
8-1) 등록된 학생 외의  학생 정보와 성적을 추가 입력받는다.
만일 등록되어있는 학생수가 최대 학생수를 초과할 수 없게 if문 설정.

8-2) 입력받은 정보를 해당되는 주소에 집어넣는다.
//&포인터변수[total_count-1]

<실행 결과>

<img width="377" alt="1" src="https://user-images.githubusercontent.com/100817654/156997548-e6d440ed-c0e7-4ae1-bde9-09773d688515.png">
<img width="601" alt="2" src="https://user-images.githubusercontent.com/100817654/156997567-85a5ea51-e46c-4744-ad31-42c9a4a8fb1a.png">
<img width="453" alt="3" src="https://user-images.githubusercontent.com/100817654/156997588-7d11fac3-a430-470d-b87b-750751c8053c.png">
<img width="598" alt="4" src="https://user-images.githubusercontent.com/100817654/156997605-51456dae-7e4f-49b6-ae07-422308ede1e4.png">
<img width="422" alt="5" src="https://user-images.githubusercontent.com/100817654/156997614-e0d8dde2-d115-45dd-803a-8de54dd0cdde.png">
<img width="630" alt="6" src="https://user-images.githubusercontent.com/100817654/156997624-0193f4f4-1f2d-418c-af8c-522f0bc9d8f9.png">
<img width="449" alt="7" src="https://user-images.githubusercontent.com/100817654/156997637-b2f2fb6c-6ff6-4767-b218-0971598d000c.png">
<img width="623" alt="8" src="https://user-images.githubusercontent.com/100817654/156997650-31dba81f-a470-45be-8ebe-5447a3cf3d26.png">
<img width="460" alt="9" src="https://user-images.githubusercontent.com/100817654/156997661-dba34e08-bc1c-444f-ba31-e44989baa2e5.png">
<img width="631" alt="10" src="https://user-images.githubusercontent.com/100817654/156997669-87752325-b638-4826-9733-3bc3adcd807c.png">
