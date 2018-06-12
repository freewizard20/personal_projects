%% 1-1 번 과제

% mot 데이터 임포트 및 plot
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_mot.mat')
plot(CA_mean,P_cyl_mean)

% 하나의 그래프에 도시
hold on

% BTSD 25도 데이터 임포트 및 plot
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_25.mat')
plot(CA_mean,P_cyl_mean,'--')

% BTSD 35도 데이터 임포트 및 plot
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_35.mat')
plot(CA_mean,P_cyl_mean,':')

% BTSD 45도 데이터 임포트 및 plot
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_45.mat')
plot(CA_mean,P_cyl_mean,'-.')


legend('Motoring','Spark timing -25','Spark timing -35','Spark timing -45')
xlabel('CAD(angle)')
ylabel('Pressure(bar)')

% 1-2 번 과제
clear all;

%% 1-2-1 intake, exhaust temperature과 MAP at IVC plot

% 변수 준비
x=zeros(1,3);
y1=zeros(1,3);
y2=zeros(1,3);%T_in_mean
y3=zeros(1,3);%T_ex_mean
 
% BTSD 25도 데이터 입력
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_25.mat')
x(1)=-Spark_timing_mean;
y1(1)=MAP_ivc_mean;
y2(1)=T_in_mean;
y3(1)=T_ex_mean;
 
% BTSD 35도 데이터 입력
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_35.mat')
x(2)=-Spark_timing_mean;
y1(2)=MAP_ivc_mean;
y2(2)=T_in_mean;
y3(2)=T_ex_mean;
 
% BTSD 45도 데이터 입력
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_45.mat')
x(3)=-Spark_timing_mean;
y1(3)=MAP_ivc_mean;
y2(3)=T_in_mean;
y3(3)=T_ex_mean;

% MAP 그래프 plot
figure;
plot(x,y1,'*-');
xlim([22,48]);

xlabel('BTDC(degree)');
ylabel('MAP at IVC');
title('MAP at IVC');

% intake 그래프 plot
figure;
plot(x,y2,'*-');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('Temperature of intake gas(℃)');
title('Temperature of intake gas(℃)');

% exhaust 그래프 plot
figure;
plot(x,y3,'*-');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('Temperature of exhaust gas(℃)');
title('Temperature of exhaust gas(℃)');

%% 1-2-1 번 과제

clear all

% 엔진의 물성치
l=0.101;
a=0.029;
b=0.077;

% 엔탈피 값 및 보간을 위한 데이터
intakex=0:10:60;
intakey=[-148.34 -137.93 -127.48 -116.99 -106.45 -95.86 -85.24]
% exhaust gas 엔탈피
exx=400:50:700
exy=[-2486.4 -2427.1 -2366.9 -2305.9 -2244.0 -2181.4 -2118.0]

% 출력할 결과값 변수
PP=zeros(1,3);
GP=zeros(1,3);
NP=zeros(1,3);
x=zeros(1,3);
t=zeros(1,3);
p=zeros(1,3);
e=zeros(1,3);
% 열손실
q=zeros(1,3);
% 배기가스 열손실
eq=zeros(1,3);
lhv=zeros(1,3);

% BTSD 25도 값 계산
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_25.mat');
x(1)=-Spark_timing_mean;
s=a*cosd(CA_mean)+sqrt(l.^2-(a*sind(CA_mean)).^2);
P=P_cyl_mean*10^5;
V=-pi/4*b^2*s;
V1=V([1:308]);
V2=V([309:707]);
V3=V([708:800]);
P1=P([1:308]);
P2=P([309:707]);
P3=P([708:800]);

% 각 구간의 일 계산
W1=trapz(V1,P1);
W2=trapz(V2,P2);
W3=trapz(V3,P3);

% gross work, pump work 계산
pw=W1+W3;
gw=W2;
gw=W1+W2+W3;
V_displacement=pi*(b^2)/4*(max(s)-min(s));
mass=MAP_ivc_mean*10^5*V_displacement/(274.73*(T_in_mean+273));

% MEP 계산
PP(1)=(pw/V_displacement)/(10^5);%bar단위
GP(1)=(gw/V_displacement)/(10^5);
NP(1)=PP(1)+GP(1);

% 토크,출력, 효율, lhv, 열손실, 배기가스 열손실 계산
t(1)=gw/(4*pi);
p(1)=(gw*RPM_mean)/120;
e(1)=gw/(mass*0.0623*44.7*10^6);
lhv(1)=mass*0.0623*44.7*10^6;
q(1)=(interp1(intakex,intakey,T_in_mean)-interp1(exx,exy,T_ex_mean))*mass*10^3-gw;
eq(1)=mass*1.186*10^3*(T_ex_mean-25);

% BTSD 35도 값 계산
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_35.mat');
x(2)=-Spark_timing_mean;
s=a*cosd(CA_mean)+sqrt(l.^2-(a*sind(CA_mean)).^2);
P=P_cyl_mean*10^5;
V=-pi/4*b^2*s;
V1=V([1:312]);
V2=V([313:710]);
V3=V([711:798]);
P1=P([1:312]);
P2=P([313:710]);
P3=P([711:798]);

W1=trapz(V1,P1);
W2=trapz(V2,P2);
W3=trapz(V3,P3);

pw=W1+W3;
gw=W2;
gw=W1+W2+W3;
V_displacement=pi*(b^2)/4*(max(s)-min(s));
mass=MAP_ivc_mean*10^5*V_displacement/(274.73*(T_in_mean+273));
 
PP(2)=(pw/V_displacement)/(10^5);
GP(2)=(gw/V_displacement)/(10^5);
NP(2)=PP(2)+GP(2);
t(2)=gw/(4*pi);
p(2)=(gw*RPM_mean)/120;
e(2)=gw/(mass*0.0623*44.7*10^6);
lhv(2)=mass*0.0623*44.7*10^6;
q(2)=(interp1(intakex,intakey,T_in_mean)-interp1(exx,exy,T_ex_mean))*mass*10^3-gw
eq(2)=mass*1.186*10^3*(T_ex_mean-25);
 
% BTSD 45도 값 계산
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_45.mat');
x(3)=-Spark_timing_mean;
s=a*cosd(CA_mean)+sqrt(l.^2-(a*sind(CA_mean)).^2);
P=P_cyl_mean*10^5;
V=-pi/4*b^2*s;
V1=V([1:312]);
V2=V([313:710]);
V3=V([711:799]);
P1=P([1:312]);
P2=P([313:710]);
P3=P([711:799]);
 
W1=trapz(V1,P1);
W2=trapz(V2,P2);
W3=trapz(V3,P3);
 
pw=W1+W3;
gw=W2;
gw=W1+W2+W3;
V_displacement=pi*(b^2)/4*(max(s)-min(s));
mass=MAP_ivc_mean*10^5*V_displacement/(274.73*(T_in_mean+273));
 
PP(3)=(pw/V_displacement)/(10^5);%bar단위
GP(3)=(gw/V_displacement)/(10^5);
NP(3)=PP(3)+GP(3);
t(3)=gw/(4*pi);
p(3)=(gw*RPM_mean)/120;
e(3)=gw/(mass*0.0623*44.7*10^6);
lhv(3)=mass*0.0623*44.7*10^6;
q(3)=(interp1(intakex,intakey,T_in_mean)-interp1(exx,exy,T_ex_mean))*mass*10^3-gw
eq(3)=mass*1.186*10^3*(T_ex_mean-25);

% 그래프 Plot
figure;
plot(x,PP,'*-');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('PP(bar)');
title('PP');
 
figure;
plot(x,GP,'*-');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('GP(bar)');
title('GP');
 
figure;
plot(x,NP,'*-');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('NP(bar)');
title('NP');
 
figure;
plot(x,t,'*-');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('t(Nㆍm)');
title('t');
 
figure;
plot(x,p,'*-');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('p(W)');
title('p');
 
figure;
plot(x,e,'*-');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('e');
title('e');
 
figure;
plot(x,q,'*-');
hold on
plot(x,lhv,'*-.');
plot(x,eq,'*--');
xlim([22,48]);
xlabel('BTDC(degree)');
ylabel('(J/cycle)');
title('Heat loss');
legend('heat loss','fuel lhv','exhaust heat loss');

%% 1-4 오토 사이클 이론값 계산
clear all;

% 엔진 물성치
l=0.101;
a=0.029;
b=0.077;
ga=8.5;

% 45도에 대한 otto PV 선도 plot을 위한 값 추출
load('C:\Users\okjin\Desktop\기공실2\data\1_2조_엔진B_데이터\1_2_b_45.mat');

% 기본 변수 준비
d=[-180:1:180];
otto_s=0.130-(a*cosd(d)+sqrt(l.^2-(a*sind(d)).^2));
V_TDC=((pi*(0.077/2)^2)*2*a)/(ga-1)
v=V_TDC+pi/4*b^2*otto_s;
p(1)=MAP_ivc_mean*10^5;
for i = 0 : 1 : 180 
    p(i+1)=p(1)*(v(1)/v(i+1))^1.35; 
    i=i+1;
end

% intake temperature을 기반으로 각 점의 온도 및 압력 계산
T_2=(T_in_mean+273.15)*(v(1)/v(181))^0.35-273.15;
m=p(181)*v(181)/(287*(T_2+273.15));
T_3= T_2+398.596383771578/(m*821);
P_3= m*287*(T_3+273.15)/v(181);
p(182)=P_3;

% PV 값 기반으로 이론적 p 계산
for i = 181 : 1 : 360 
    p(i+1)=P_3*(v(181)/v(i+1))^1.35;
    i=i+1;
end

% gross work 계산결과 출력
grosswork=trapz(v,p)

% 실제 PV 선도 계산
V_real = V_TDC+pi/4*b^2*(0.130-(a*cosd(CA_mean)+sqrt(l.^2-(a*sind(CA_mean)).^2)));
P_real = P_cyl_mean*10^5;

% 그래프 plot
figure;
plot(v,p,'-');
hold on;
plot(V_real,P_real,'--');
legend('이론적 오토사이클','실험값');
xlabel('부피(m^3)');
ylabel('압력(Pa)');
title('PV선도 비교');

% gross work 비교 그래프 plot
x = zeros(3);
y = zeros(3);
y1 = zeros(3);

x(1)=25;
x(2)=35;
x(3)=45;

% 1-2의 계산 결과 이용 - 실제 gross work
y(1)=96.9199;
y(2)=112.3426;
y(3)=114.4348;

% 1-4의 계산 결과 이용 - 이론적 gross work
y1(1)=204.1213;
y1(2)=208.0973;
y1(3)=209.8426;

% 그래프 plot
plot(x,y)
hold on
plot(x,y1,'--')
xlim([22,48])
ylabel('Gross work(J)')
xlabel('BTDC(degree)')
title('오토사이클과 실제 엔진의 gross work 차이')

%% 실험C 1-1
clear all

% 결과값 변수 준비
x=zeros(1,3);
y1=zeros(1,3);
y2=zeros(1,3);
y3=zeros(1,3);
 
% LOW MAP 데이터 입력
load('0102_c_low.mat');
x(1)=MAP_ivc_mean;
y1(1)=T_in_mean;
y2(1)=T_ex_mean;
y3(1)=max(P_cyl_mean);
 
% MID MAP 데이터 입력
load('0102_c_mid.mat');
x(2)=MAP_ivc_mean;
y1(2)=T_in_mean;
y2(2)=T_ex_mean;
y3(2)=max(P_cyl_mean);

% HIGH MAP 데이터 입력
load('0102_c_high.mat'); 
x(3)=MAP_ivc_mean;
y1(3)=T_in_mean;
y2(3)=T_ex_mean;
y3(3)=max(P_cyl_mean);

% 그래프 plot
figure;
plot(x,y1,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('Temperature of intake gas(℃)');
title('intake gas 온도 분포');
 
figure;
plot(x,y2,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('Temperature of exhaust gas(℃)');
title('exhaust gas 온도 분포');
 
figure;
plot(x,y3,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('Maximum Pressure of cylinder(bar)');
title('Maximum Pressure of cylinder');

%% 2번
clear all

% 엔진 물성치
l=0.101;
a=0.029;
b=0.077;
ga=8.5;

% intake, exhaust 엔탈피 값
intakex=0:10:60;
intakey=[-148.34 -137.93 -127.48 -116.99 -106.45 -95.86 -85.24];
exx=400:50:700
exy=[-2486.4 -2427.1 -2366.9 -2305.9 -2244.0 -2181.4 -2118.0];

% 결과 변수 준비
PP=zeros(1,3);
GP=zeros(1,3);
NP=zeros(1,3);
x=zeros(1,3);
t=zeros(1,3);
p=zeros(1,3);
e=zeros(1,3);
q=zeros(1,3);
eq=zeros(1,3);
lhv=zeros(1,3);
 
% LOW MAP 데이터 계산
load('0102_c_low.mat');
x(1)=MAP_ivc_mean;

s=0.130-(a*cosd(CA_mean)+sqrt(l.^2-(a*sind(CA_mean)).^2));
V_TDC=((pi*(b/2)^2)*2*a)/(ga-1);
V=V_TDC+pi/4*b^2*s;
P=P_cyl_mean*10^5;

V1=V([1:305]);
V2=V([306:704]);
V3=V([705:799]);
P1=P([1:305]);
P2=P([306:704]);
P3=P([705:799]);

% 각 구간의 일 계산
W1=trapz(V1,P1);
W2=trapz(V2,P2);
W3=trapz(V3,P3);

% pump work, gross work, net work 계산
pw=W1+W3;
gw=W2;
nw=W1+W2+W3;

% MEP 계산
V_displacement=pi*(b^2)/4*(max(s)-min(s));
PP(1)=(pw/V_displacement)/(10^5);%bar단위
GP(1)=(gw/V_displacement)/(10^5);
NP(1)=PP(1)+GP(1);
 
% 토크, 출력, 효율 계산
mass=MAP_ivc_mean*10^5*V_displacement/(274.73*(T_in_mean+273));
t(1)=gw/(4*pi);
p(1)=(gw*RPM_mean)/120;
e(1)=gw/(mass*0.0623*44.7*10^6);
 
% LHV, 열손실, 배기 열손실 계산
lhv(1)=mass*0.0623*44.7*10^6;
q(1)=(interp1(intakex,intakey,T_in_mean)-interp1(exx,exy,T_ex_mean))*mass*10^3-gw;
eq(1)=mass*1.186*10^3*(T_ex_mean-25);

% MID MAP 결과값 계산
load('0102_c_mid.mat');
x(2)=MAP_ivc_mean;
s=0.130-(a*cosd(CA_mean)+sqrt(l.^2-(a*sind(CA_mean)).^2));
V_TDC=((pi*(b/2)^2)*2*a)/(ga-1);
V=V_TDC+pi/4*b^2*s;
P=P_cyl_mean*10^5; 

V1=V([1:299]);
V2=V([300:697]);
V3=V([698:799]);
P1=P([1:299]);
P2=P([300:697]);
P3=P([698:799]);

W1=trapz(V1,P1);
W2=trapz(V2,P2);
W3=trapz(V3,P3);
pw=W1+W3;
gw=W2;
gw=W1+W2+W3;

V_displacement=pi*(b^2)/4*(max(s)-min(s));
PP(2)=(pw/V_displacement)/(10^5);
GP(2)=(gw/V_displacement)/(10^5);
NP(2)=PP(2)+GP(2);

mass=MAP_ivc_mean*10^5*V_displacement/(274.73*(T_in_mean+273));
t(2)=gw/(4*pi);
p(2)=(gw*RPM_mean)/120;
e(2)=gw/(mass*0.0623*44.7*10^6);
 
lhv(2)=mass*0.0623*44.7*10^6;
q(2)=(interp1(intakex,intakey,T_in_mean)-interp1(exx,exy,T_ex_mean))*mass*10^3-gw;
eq(2)=mass*1.186*10^3*(T_ex_mean-25);

% HIGH MAP 결과값 계산
load('0102_c_high.mat');
x(3)=MAP_ivc_mean;
s=0.130-(a*cosd(CA_mean)+sqrt(l.^2-(a*sind(CA_mean)).^2));
V_TDC=((pi*(b/2)^2)*2*a)/(ga-1);%압축비를 통하여 V_TDC를 구한다
V=V_TDC+pi/4*b^2*s;%실린더의 부피
P=P_cyl_mean*10^5; %bar단위를 Pa단위로 변환

V1=V([1:284]);
V2=V([285:682]);
V3=V([683:799]);
P1=P([1:284]);
P2=P([285:682]);
P3=P([683:799]);

W1=trapz(V1,P1);
W2=trapz(V2,P2);
W3=trapz(V3,P3);
pw=W1+W3;
gw=W2;
gw=W1+W2+W3;

V_displacement=pi*(b^2)/4*(max(s)-min(s));
PP(3)=(pw/V_displacement)/(10^5);%bar단위
GP(3)=(gw/V_displacement)/(10^5);
NP(3)=PP(3)+GP(3);

mass=MAP_ivc_mean*10^5*V_displacement/(274.73*(T_in_mean+273));
t(3)=gw/(4*pi);
p(3)=(gw*RPM_mean)/120;
e(3)=gw/(mass*0.0623*44.7*10^6);

lhv(3)=mass*0.0623*44.7*10^6;
q(3)=(interp1(intakex,intakey,T_in_mean)-interp1(exx,exy,T_ex_mean))*mass*10^3-gw;
eq(3)=mass*1.186*10^3*(T_ex_mean-25);
 
% 그래프 plot
figure;
plot(x,PP,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('PP(bar)');
title('PP');
 
figure;
plot(x,GP,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('GP(bar)');
title('GP');
 
figure;
plot(x,NP,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('NP(bar)');
title('NP');
 
figure;
plot(x,t,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('t(Nㆍm)');
title('t');
 
figure;
plot(x,p,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('출략(W)');
title('출력');
 
figure;
plot(x,e,'*-');
xlim([0.42,0.57]);
xlabel('MAP(bar)');
ylabel('e');
title('e');
 
figure;
plot(x,q,'*-');
hold on
plot(x,lhv,'*-.');
plot(x,eq,'*--');
xlim([0.42,0.75]);
xlabel('MAP(bar)');
ylabel('(J/cycle)');
title('스로틀 개방에 따른 열손실');
legend('열전달 손실','lhv','배기에 의한 열에너지 손실');
