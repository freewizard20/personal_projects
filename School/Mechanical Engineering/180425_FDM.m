%% 초기화와 데이터 불러오기, 기본적인 데이터 처리(no1~no4)
close all;
clear all;
clc;
experiment='B';
%데이터 불러오기
%열전대값 불러오기
open_path='C:\Users\okjin\Desktop\온도C\실험B,C\DATA\';
files_dat=[open_path,'온도실험',experiment,'_12조.txt'];%csv파일은 matlab에서 값을 읽어올 때 오류가 나므로 txt파일로 바꿔서 한다
b=fopen(files_dat,'r');
data_thermo=textscan(b,['%*d %*s %*s' repmat('%f %*f',[1,16])],'Collectoutput',1,'Headerlines',25);
steady_state_data_thermocouple=data_thermo{1,1}(size(data_thermo{1,1},1),:);
fclose(b);

%Hue값 불러오기
files_dat=[open_path,experiment,'test.txt'];
a=fopen(files_dat,'r');
data_inform=textscan(a,'%s',1,'Delimiter','\n');%data headerline값 읽기 topleft&bottomright
n=deal(regexp(data_inform{1,1}{1,1},'\d*','match'));%data headerline에서 숫자 추출
Left=str2num(n{1,1});
Top=str2num(n{1,2});
Right=str2num(n{1,3});
Bottom=str2num(n{1,4});

data_x=textscan(a,['%s',repmat('%f',[1,Right-Left+1])],1,'collectOutput',1);%x축 좌표값 데이터 읽어오기
data_x=data_x{1,2};%'YX' text를 버리고 x축 좌표값만 남긴다
data=textscan(a,[repmat('%f',[1,Right-Left+2])],'collectOutput',1);%나머지 데이터 불러오기
data_y=data{1,1}(:,1);%y축 좌표값 저장
data=data{1,1}(1:Bottom-Top+1,2:Right-Left+2);%실제 데이터 값들
fclose(a);

%overflow 보정
for i=1:size(data,1)
    for j=1:size(data,2)
        if data(i,j)<100
            data(i,j)=data(i,j)+256;
        end
    end
end
%average
data_mean=mean(data,2);%y좌표 기준 x좌표 평균

%% temperature_experiment_no1(Hue value calibration)

%Hue vs temperature그래프 그리기(curve fitting은 curve fitting 앱 이용)
figure();
Hue_data_thermolocation=data_mean(length(data_mean):-floor((length(data_mean)-1)/15):1);
plot(Hue_data_thermolocation,steady_state_data_thermocouple,'o');

%Hue값을 온도값으로 변환
if experiment=='A'
    Hue_temperature=0.0009913*data.^2-0.236*data+21.82;
else
    Hue_temperature=0.0006219*data.^2-0.209*data+32.51;
end

%Hue값의 x,y좌표 계산
Fin_length=28.5;
Fin_width=10;
data_y1=(data_y-Top)*Fin_length/(Bottom-Top);%Huecalc은 위에서 아래로 갈수록 숫자가 커진다.
data_x1=(data_x-Left)*Fin_width/(Right-Left);

%2-d temperature distribution plot
figure();
mesh(data_x1,data_y1,Hue_temperature);
xlabel('Width(cm)');
ylabel('Length(cm)');
zlabel('Temperature(℃)');
title(['실험',experiment',' 2-D Temperature Distribution']);

%% temperature_experiment_no2
%analytic solution
T_inf = 20.67;%공기 온도. 처음 16개 핀의 온도를 평균내서 구한다
T_b = 38.46;
h = 3.5345; %대류 연전달계수
k = 401; %열전도율
L = 0.27 + 0.015; %tip까지의 거리
P = (0.1+0.002)*2; %둘레
A_c = 0.1 * 0.002;
m=sqrt((h*P)/(k*A_c));

x1=0:0.002:L;
T1=T_inf+(T_b-T_inf)*(cosh(m*(L-x1))+(h/(m*k))*sinh(m*(L-x1)))/(cosh(m*L)+(h/(m*k))*sinh(m*L));

figure();
plot(x1*100,T1);

hold on;

%thermocouple
plot([0:1.8:27],steady_state_data_thermocouple);

%Hue
%Hue값을 온도값으로 변환
if experiment=='A'
    Hue_temperature=0.0009913*data.^2-0.236*data+21.82;
else
    Hue_temperature=0.0006219*data.^2-0.209*data+32.51;
end

%Hue값의 x,y좌표 계산
Fin_length=27;
Fin_width=10;
data_y2=flipud((data_y-Top)*Fin_length/(Bottom-Top));%Huecalc은 위에서 아래로 갈수록 숫자가 커진다.flipud을 통해 뒤집어 준다.
data_x2=(data_x-Left)*Fin_width/(Right-Left);

plot(data_y2,mean(Hue_temperature,2));
title(['실힘',experiment,' 1-D temperature profile']);
xlabel('fin length(cm)');
ylabel('temperature(℃)');
legend('analytic solution','thermocouple','Hue');

%% temperature_experiment_no3
clear all;
%A,B에 대한 열전대값
for i='A':'B'
    %열전대값 불러오기
    open_path='C:\Users\Jaewook\Google 드라이브\학교 자료\3-2\기항실2\3. 온도\실험B\DATA\';
    files_dat=[open_path,'온도실험',i,'_56조.txt'];%csv파일은 matlab에서 값을 읽어올 때 오류가 나므로 txt파일로 바꿔서 한다
    b=fopen(files_dat,'r');
    data_thermo=textscan(b,['%*d %*s %*s' repmat('%f %*f',[1,16])],'Collectoutput',1,'Headerlines',25);
    steady_state_data_thermocouple=data_thermo{1,1}(size(data_thermo{1,1},1),:);
    fclose(b);
    
    plot([0:1.8:27],steady_state_data_thermocouple);
    hold on;
    max(steady_state_data_thermocouple)-min(steady_state_data_thermocouple);
end
title(['Natural convection vs. Forced convection(Thermocouple)']);
xlabel('fin length(cm)');
ylabel('temperature(℃)');
legend('Natural convection','Forced convection');

%% temperature_experiment_no4(Heat effectiveness, efficiency)
clc;

%이론적으로 구하는 방법
if experiment=='A'
    h = 3.5345; %대류 연전달계수
    T_base=38.46;
    T_inf=20.67;
elseif experiment=='B'
    h = 27.6; %대류 연전달계수
    T_base=22.19;
    T_inf=15.36;
end
k = 401; %열전도율
L = 0.27; %tip까지의 거리
P = (0.1+0.002)*2; %둘레
A_c = 0.1 * 0.002;
A_f = 2*0.1 * L;%양면이므로 2배를 해준다
m=sqrt((h*P)/(k*A_c));
effectiveness_theory=sqrt(k*P/(h*A_c))*(sinh(m*L)+(h/(m*k))*cosh(m*L))/(cosh(m*L)+(h/(m*k))*sinh(m*L));
efficiency_theory=effectiveness_theory*A_c/(A_f);

%Hue값을 이용하여 구하는 방법

%Hue값을 온도값으로 변환
if experiment=='A'
    Hue_temperature=0.0009913*data.^2-0.236*data+21.82;
else
    Hue_temperature=0.0006219*data.^2-0.209*data+32.51;
end

%Hue값의 x,y좌표 계산
Fin_length=27;
Fin_width=10;
data_y1=(data_y-Top)*Fin_length/(Bottom-Top)/100;%Huecalc은 위에서 아래로 갈수록 숫자가 커진다.
data_x1=(data_x-Left)*Fin_width/(Right-Left)/100;

q_f=0;
for i=1:length(data_y1)
    for j=1:length(data_x1)
        q_f=q_f+h*(Hue_temperature(i,j)-T_inf)*(data_x1(2)-data_x1(1))*(data_y1(2)-data_y1(1))*2;
    end
end

effectiveness_Hue=q_f/(h*A_c*(T_base-T_inf));
efficiency_Hue=q_f/(h*A_f*(T_base-T_inf));

%% no5
%% 데이터 가져오기
close all;
clear all;
clc;

%데이터 불러오기
%실험 A
%열전대값 불러오기
open_path='C:\Users\okjin\Desktop\온도C\실험B,C\DATA\';
files_dat=[open_path,'온도실험A_12조.csv'];
data_thermo_A=xlsread(files_dat,'온도실험A_12조','C26:AH41');
data_thermo_A=data_thermo_A(:,1:2:31);
steady_state_data_thermocouple_A=data_thermo_A(size(data_thermo_A,1),:);

%Hue값 불러오기
files_dat=[open_path,'Atest.xlsx'];
data=xlsread(files_dat,'sheet1','B3:AO139');
data_x=xlsread(files_dat,'sheet1','B2:AO2');
data_y=xlsread(files_dat,'sheet1','A3:A139');

%overflow 보정
for i=1:size(data,1)
    for j=1:size(data,2)
        if data(i,j)<100
            data(i,j)=data(i,j)+256;
        end
    end
end
%Hue값 온도 전환
Hue_temperature_A=0.0009913*data.^2-0.236*data+21.82;
%Hue값의 x,y좌표 계산
Fin_length=28.5;
Fin_width=10;
data_y_A=((data_y-min(data_y))*Fin_length/(length(data_y)-1));%Huecalc은 위에서 아래로 갈수록 숫자가 커진다.flipud을 통해 뒤집어 준다.
data_x_A=(data_x-min(data_x))*Fin_width/(length(data_x)-1);
clear data data_x data_y;

%실험 B
%열전대값 불러오기
open_path='C:\Users\okjin\Desktop\온도C\실험B,C\DATA\';
files_dat=[open_path,'온도실험B_12조.csv'];
data_thermo_B=xlsread(files_dat,'온도실험B_12조','C26:AH41');
data_thermo_B=data_thermo_B(:,1:2:31);
steady_state_data_thermocouple_B=data_thermo_B(size(data_thermo_B,1),:);

%Hue값 불러오기
files_dat=[open_path,'Btest.xlsx'];
data=xlsread(files_dat,'sheet1','B3:AS141');
data_x=xlsread(files_dat,'sheet1','B2:AS2');
data_y=xlsread(files_dat,'sheet1','A3:A141');

%overflow 보정
for i=1:size(data,1)
    for j=1:size(data,2)
        if data(i,j)<100
            data(i,j)=data(i,j)+256;
        end
    end
end
%Hue값 온도 전환
Hue_temperature_B=0.0006219*data.^2-0.209*data+32.51;
%Hue값의 x,y좌표 계산
Fin_length=28.5;
Fin_width=10;
data_y_B=((data_y-min(data_y))*Fin_length/(length(data_y)-1));%Huecalc은 위에서 아래로 갈수록 숫자가 커진다.flipud을 통해 뒤집어 준다.
data_x_B=(data_x-min(data_x))*Fin_width/(length(data_x)-1);
clear data data_x data_y;

%실험 C 열전대값 불러오기
open_path='C:\Users\okjin\Desktop\온도C\실험B,C\DATA\';
files_dat=[open_path,'온도실험C_12조.csv'];%csv파일은 matlab에서 값을 읽어올 때 오류가 나므로 txt파일로 바꿔서 한다
data_thermo_C=xlsread(files_dat,'온도실험C_12조','C26:AH40');
data_thermo_C=data_thermo_C(:,[1 3 9 13]);
steady_state_data_thermocouple_C=data_thermo_C(size(data_thermo_C,1),:);

%Hue값 불러오기
files_dat=[open_path,'Ctest.xlsx'];%csv파일은 matlab에서 값을 읽어올 때 오류가 나므로 txt파일로 바꿔서 한다
data=xlsread(files_dat,'sheet1','B3:AF134');
data_x=xlsread(files_dat,'sheet1','B2:AF2');
data_y=xlsread(files_dat,'sheet1','A3:A134');

%overflow 보정
for i=1:size(data,1)
    for j=1:size(data,2)
        if data(i,j)<100
            data(i,j)=data(i,j)+256;
        end
    end
end
%Hue값 온도 전환
Hue_temperature_C=0.4614*data-101.1;
%Hue값의 x,y좌표 계산
Fin_length=42.5;
Fin_width=10;
data_y_C=((data_y-min(data_y))*Fin_length/(length(data_y)-1));%Huecalc은 위에서 아래로 갈수록 숫자가 커진다.flipud을 통해 뒤집어 준다.
data_x_C=(data_x-min(data_x))*Fin_width/(length(data_x)-1);
clear data_x data_y;


%% no5
%Calibration
figure();
data_part1=data(57:size(data,1),:);
Hue_data_thermolocation=zeros(4,1);
Hue_data_thermolocation(1)=data_part1(round(size(data_part1,1)/225*15),round(size(data_part1,2)/100*6.67));
Hue_data_thermolocation(2)=data_part1(round(size(data_part1,1)/225*85),round(size(data_part1,2)/100*37.78));
Hue_data_thermolocation(3)=data_part1(round(size(data_part1,1)/225*155),round(size(data_part1,2)/100*68.89));
Hue_data_thermolocation(4)=data_part1(round(size(data_part1,1)/225*225),round(size(data_part1,2)/100*100));

plot(Hue_data_thermolocation,steady_state_data_thermocouple_C,'o');
xlabel('Hue값');
ylabel('열전대값(℃)');
title('열전대값 오류');

%2-D distribution
figure();
surf(data_x_C,data_y_C,Hue_temperature_C);
shading interp;
xlabel('width(cm)');
ylabel('length(cm)');
zlabel('temperature(℃)');
title('2-D temperature distribution');
axis([0 10 0 60 -10 40]);

%effectiveness,efficiency
T_inf=mean(data_thermo_C(1,:),2)
T_base=steady_state_data_thermocouple_C(end)
T_tip=steady_state_data_thermocouple_C(1)
%실험C q_f계산
q_f=0;
h=3.6739;
for i=55:length(data_y_C)
    for j=1:length(data_x_C)
        q_f=q_f+h*(Hue_temperature_C(i,j)-T_inf)*(data_x_C(2)-data_x_C(1))*(data_y_C(2)-data_y_C(1))*2/10000;
    end
end
for i=1:54
    for j=5:9
        q_f=q_f+h*(Hue_temperature_C(i,j)-T_inf)*(data_x_C(2)-data_x_C(1))*(data_y_C(2)-data_y_C(1))*2/10000;
    end
end
for i=1:54
    for j=20:24
        q_f=q_f+h*(Hue_temperature_C(i,j)-T_inf)*(data_x_C(2)-data_x_C(1))*(data_y_C(2)-data_y_C(1))*2/10000;
    end
end

A_c = 0.1 * 0.002;
A_f = 2*(0.1 * 0.225+0.15*0.04);
effectiveness_Hue=q_f/(h*A_c*(T_base-T_inf));
efficiency_Hue=q_f/(h*A_f*(T_base-T_inf));
%% New fin analysis
clear all;
clc;
close all;
T_inf = 20.67;%공기 온도
T_b = 38.46;
h = 3.5345; %대류 연전달계수
k = 401; %열전도율

L1=0.24;
L2=0.08;
w=0.1;
w1=0.02;
w2=0.06;
t=0.002;%node 분할 단위, fin 두께
% set up matrix
x_num=w/t+1;
x_num_1=w1/t+1;
x_num_2=(w1+w2)/t+1;
y_num=uint8((L1+L2)/t+1);
y_num_1=uint8((L1/t+1));

T_n=ones(x_num,y_num)*T_inf;
T_n(1:x_num,1) = T_b;

errormax=1e-7;
error=1;
iter=0;

while error>errormax
    T_old = T_n;
    
    for i=2:x_num-1   %큰 직사각형 내부
        for j=2:y_num_1-1
            T_n(i,j) = (k*(T_n(i+1,j)+T_n(i-1,j)+T_n(i,j-1)+T_n(i,j+1))+2*h*t*T_inf)/(4*k+2*h*t);
        end
    end
    
    for i=x_num_1+1:x_num_2-1   %돌출부 내부
        for j=y_num_1:y_num-1
            T_n(i,j) = (k*(T_n(i+1,j)+T_n(i-1,j)+T_n(i,j-1)+T_n(i,j+1))+2*h*t*T_inf)/(4*k+2*h*t);
        end
    end
    
    for i=2:x_num_1-1   %큰 직사각형 윗줄
        T_n(i,y_num_1)=(k*T_n(i-1,y_num_1)/2+k*T_n(i+1,y_num_1)/2+k*T_n(i,y_num_1-1)+2*h*t*T_inf)/(2*k+2*h*t);
    end
    for i=x_num_2+1:x_num-1
        T_n(i,y_num_1)=(k*T_n(i-1,y_num_1)/2+k*T_n(i+1,y_num_1)/2+k*T_n(i,y_num_1-1)+2*h*t*T_inf)/(2*k+2*h*t);
    end
    
    for i=x_num_1+1:x_num_2-1   %돌출부 윗줄
        T_n(i,y_num)=(k*T_n(i-1,y_num)/2+k*T_n(i+1,y_num)/2+k*T_n(i,y_num-1)+2*h*t*T_inf)/(2*k+2*h*t);
    end
    
    for j=2:y_num_1-1  %큰 직사각형 왼쪽
        T_n(1,j)=(k*T_n(1,j+1)/2+k*T_n(1,j-1)/2+k*T_n(2,j)+2*h*t*T_inf)/(2*k+2*h*t);
    end
    for j=y_num_1+1:y_num-1  %돌출부 왼쪽
        T_n(x_num_1,j)=(k*T_n(x_num_1,j+1)/2+k*T_n(x_num_1,j-1)/2+k*T_n(x_num_1+1,j)+2*h*t*T_inf)/(2*k+2*h*t);
    end
    
    for j=2:y_num_1-1 %큰 직사각형 오른쪽
        T_n(x_num,j)=(k*T_n(x_num,j+1)/2+k*T_n(x_num,j-1)/2+k*T_n(x_num-1,j)+2*h*t*T_inf)/(2*k+2*h*t);
    end
    for j=y_num_1+1:1:y_num-1 %돌출부 오른쪽
        T_n(x_num_2,j)=(k*T_n(x_num_2,j+1)/2+k*T_n(x_num_2,j-1)/2+k*T_n(x_num_2-1,j)+2*h*t*T_inf)/(2*k+2*h*t);
    end
    
    %꼭지점
    T_n(1,y_num_1)=(k*T_n(2,y_num_1)+k*T_n(1,y_num_1-1)+h*t*T_inf*3)/(2*k+3*h*t);
    T_n(x_num_1,y_num)=(k*T_n(x_num_1+1,y_num)+k*T_n(x_num_1,y_num-1)+h*t*T_inf*3)/(2*k+3*h*t);
    T_n(x_num,y_num_1)=(k*T_n(x_num-1,y_num_1)+k*T_n(x_num,y_num_1-1)+h*t*T_inf*3)/(2*k+3*h*t);
    T_n(x_num_2,y_num)=(k*T_n(x_num_2-1,y_num)+k*T_n(x_num_2,y_num-1)+h*t*T_inf*3)/(2*k+3*h*t);
    T_n(x_num_1,y_num_1)=(k*T_n(x_num_1,y_num_1+1)+k*T_n(x_num_1-1,y_num_1)+2*k*T_n(x_num_1+1,y_num_1)+2*k*T_n(x_num_1,y_num_1-1)+5*h*t*T_inf)/(6*k+5*h*t);
    T_n(x_num_2,y_num_1)=(k*T_n(x_num_2,y_num_1+1)+k*T_n(x_num_2+1,y_num_1)+2*k*T_n(x_num_2-1,y_num_1)+2*k*T_n(x_num_2,y_num_1-1)+5*h*t*T_inf)/(6*k+5*h*t);
            
    iter = iter+1;
    error = max(max(abs(T_n-T_old)));
end
iter
x=0:t:w;
y=0:t:(L1+L2);

figure();
y=fliplr(y);%그래프 방향을 바꿔주기 위해(보기 편하도록)
surf(x,y,T_n');
shading interp;
xlabel('width[m]');
ylabel('length[m]');
zlabel('Temperature[℃]');
title('새로운 fin 2-D distribution');

%new fin q_f계산
q_f=0;
for i=1:x_num
    for j=1:y_num_1
        q_f=q_f+h*(T_n(i,j)-T_inf)*t*t*2;
    end
end
for i=x_num_1:x_num_2
    for j=y_num_1+1:y_num
         q_f=q_f+h*(T_n(i,j)-T_inf)*t*t*2;
    end
end

A_c = 0.1 * 0.002;
A_f = 2*(0.1 * 0.24+0.06*0.08);%양면이므로 2배를 해준다
effectiveness=q_f/(h*A_c*(T_b-T_inf));
efficiency=q_f/(h*A_f*(T_b-T_inf));
