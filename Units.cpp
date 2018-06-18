//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
double num;
int n,m;
char origin[10];
char aim[10];
char input_origin[10][10];
char input_aim[10][10];
char weight[10][10] = {"Gg","Mg","kg","g","mg","ug","lb","oz"};
double WEIGHT[10] = {1000000,1000,1,0.001,0.000001,0.000000001,0.453592,0.028348};
char lenth[10][10] = {"Mm","km","m","dm","cm","mm","ft","in","yd"};
double LENTH[10] = {1000000,1000,1,0.1,0,01,0.001,0.3048,0.0254,0.9144};
char press[10][10] = {"Kgf","Mpa","Bar","Kpa","mBar","psi","atm","mmHg"};
double PRESS[10] = {1,10.19716,1.01972,0.010197,0.0010197,0.07031,1.033228,0.0013595}; 
char time[10][10] = {"h","min","s","ms","day","week"};
double TIME[10] = {60,1,1.0/60,1.0/60000,60*24,60*24*7};
char volume[10][10] = {"m^3","L","ml","ft^3","in^3","UKgal","USgal","USbbl"};
double VOLUME[10] = {61023.7,61.0237,0.0610237,1728,1,277.42,231,9701.794};


class change{
	public:
		char origin[10];
		char aim[10];
		void input(double a,char x[10],char y[10]){
			num = a;
			strcpy(origin,x);
			strcpy(aim,y);
		}
		void ChangeToTemp(){
			int i=0;
			int flag_weight = 0;
			int flag_lenth = 0;
			int flag_press = 0;
			int flag_time = 0;
			int flag_volume = 0;
			for(i=0;i<10;i++){
				if(strcmp(origin,weight[i])==0){
					flag_weight = 1;
					break;
				}
				if(strcmp(origin,lenth[i])==0){
					flag_lenth = 1;
					break;
				}
				if(strcmp(origin,press[i])==0){
					flag_press = 1;
					break;
				}
				if(strcmp(origin,time[i])==0){
					flag_time = 1;
					break;
				}
				if(strcmp(origin,volume[i])==0){
					flag_volume = 1;
					break;
				}
			}
			if(flag_weight)	num = num*WEIGHT[i];
			if(flag_lenth) num = num*LENTH[i];
			if(flag_press) num = num*PRESS[i];
			if(flag_time) num = num*TIME[i];
			if(flag_volume) num = num*VOLUME[i];
		}
		void TempToAim(){
			int i = 0;
			int flag_weight = 0;
			int flag_lenth = 0;
			int flag_press = 0;
			int flag_time = 0;
			int flag_volume = 0;
			for(i=0;i<10;i++){
				if(strcmp(aim,weight[i])==0){
					flag_weight = 1;
					break;
				}
				if(strcmp(aim,lenth[i])==0){
					flag_lenth = 1;
					break;
				}
				if(strcmp(aim,press[i])==0){
					flag_press = 1;
					break;
				}
				if(strcmp(aim,time[i])==0){
					flag_time = 1;
					break;
				}
				if(strcmp(aim,volume[i])==0){
					flag_volume = 1;
					break;
				}
			}
			if(flag_weight)	num = num/WEIGHT[i];
			if(flag_lenth) num = num/LENTH[i];
			if(flag_press) num = num/PRESS[i];
			if(flag_time) num = num/TIME[i];
			if(flag_volume) num = num/VOLUME[i];
			//cout<<num<<endl;
		}
		
		
	private:
};  
void setup(){
	cout<<"可选单位:"<<endl;
	cout<<"Gg	Mg	kg	g	mg	ug	lb	oz"<<endl;
	cout<<"Mm	km	m	dm	cm	mm	ft	in	yd"<<endl;
	cout<<"Kgf	Mpa	Bar	Kpa	mBar	psi	atm	mmHg"<<endl;
	cout<<"h	min	s	ms	day	week"<<endl;
	cout<<"m^3	L	ml	ft^3	in^3	UKgal	USgal	USbbl"<<endl;
	memset(origin,0,sizeof(origin));
	memset(aim,0,sizeof(aim));
	memset(input_origin,0,sizeof(input_origin));
	memset(input_aim,0,sizeof(input_aim));
	cout<<"请输入原数值:";cin>>num;
	cout<<"请输入原单位所含基本单位数目";cin>>n;
	cout<<"输入原单位 基本单位之间用空格隔开(eg: kg m) :";
	for(int i=0;i<n;i++){
		cin>>input_origin[i];
	}
	cout<<"请输入目标单位所含基本单位数目";cin>>m;
	cout<<"请输入目标单位 基本单位之间用空格隔开 (eg:kg m) :";
	for(int i=0;i<m;i++){
		cin>>input_aim[i];
	} 
}
int juge(int m,int n){//juge origin_input[m], aim_input[n]
	int Weight = 0,Lenth = 0,Press=0,Time=0,Volume=0;
	for(int i=0;i<10;i++){
		if(strcmp(input_origin[m],weight[i])==0){
			Weight = 1;break;
		}
		if(strcmp(input_origin[m],lenth[i])==0){
			Lenth = 1;break;
		}
		if(strcmp(input_origin[m],press[i])==0){
			Press = 1;break;
		}
		if(strcmp(input_origin[m],time[i])==0){
			Time = 1;break;
		}
		if(strcmp(input_origin[m],volume[i])==0){
			Volume = 1;break;
		}
	}
	if(Weight){
		int i;
		for(i=0;i<10;i++){
			if(strcmp(input_aim[n],weight[i])==0) break;
		}
		if(i<10) return 1;
		else return 0;
	}
	if(Lenth){
		int i;
		for(i=0;i<10;i++){
			if(strcmp(input_aim[n],lenth[i])==0) break;
		}
		if(i<10) return 1;
		else return 0;
	}
	if(Press){
		int i;
		for(i=0;i<10;i++){
			if(strcmp(input_aim[n],press[i])==0) break;
		}
		if(i<10) return 1;
		else return 0;
	}
	if(Time){
		int i;
		for(i=0;i<10;i++){
			if(strcmp(input_aim[n],time[i])==0) break;
		}
		if(i<10) return 1;
		else return 0;
	}
	if(Volume){
		int i;
		for(i=0;i<10;i++){
			if(strcmp(input_aim[n],volume[i])==0) break;
		}
		if(i<10) return 1;
		else return 0;
	}
}
int main(){
	while(1){
		change Change;
		setup();
		int cnt  = 0;
		int flag = 0;
		for(int i=0;i<n;i++){
			strcpy(origin,input_origin[i]);
			cnt = 0;
			for(int j=0;j<m;j++){
				if(!juge(i,j)){
					cnt++;
					if(cnt==m) flag = 1; 
					continue;
				}
				strcpy(aim,input_aim[j]);
				//cout<<origin<<" "<<aim<<" "; 
				Change.input(num,origin,aim);
				Change.ChangeToTemp();
				Change.TempToAim();
			}
		}
		if(flag) cout<<"输入不合法，请重新输入"<<endl;
		else cout<<"结果数值为: "<<num<<endl;
		cout<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<endl;
	}
	return 0;
}
