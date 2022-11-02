#include<bits/stdc++.h>
#include<time.h>
#include<cstdlib>
#include<sstream>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fastin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
stringstream s;
typedef long long ll;
ll mknum(int wei){
	ll now=0;
	for(int i=1;i<=wei;i++){
		now=10ll*now+rand()%10;
	}
	return now;
}
void str(int len){
	for(int i=1;i<=len;i++){
		putchar('a'+rand()%3);
	}putchar('\n');
}
double x[8]={0,0,1,1,0,0,1,1};
double y[8]={0,1,1,0,0,1,1,0};
double z[8]={-1,-1,-1,-1,1,1,1,1};
//三个维度坐标变化
mt19937 rd(time(0));
int ans[36] = {0,1,2,2,3,0,4,5,1,1,0,4,1,5,6,6,2,1,7,6,5,5,4,7,3,2,6,6,7,3,4,0,3,3,7,4};
//构建一个立方体所需要的边
vector<pair<double, double> > a;
double step;
int tot = 0;
void heng(int x, int y, int len){
	for(int i = 0; i < len; i++){
		a.push_back(make_pair(x + i, y));
		++ tot;
	}
}
void shu(int x, int y, int len){
	for(int i = 0; i < len; i++){
		a.push_back(make_pair(x, y - i));
		tot++;
	}
}
void pie(int x, int y, int len){
	for(int i = 0; i < len; i++){
		a.push_back(make_pair(x - i, y - i));
		++tot;
	}
}
double change(){
	step = 1.0/6;
	for(int i = 0; i < a.size(); i++){
		a[i].first *= (2 * step);
		a[i].second *= (2 * step);
	}
}
int main(int argc,char *argv[]){
	int random;
	if(argc>1){
		s.clear();
		s<<argv[1];
		s>>random;
	}
	srand(random);
	std::mt19937 rd(random);
	//以上是初始化随机内容
	string s[8];
	s[0] = "), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f) },\n";
	s[1] = "), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },\n";
	s[2] = "), XMFLOAT4(1.0f, 1.0f, 0.0f, 1.0f) },\n";
	s[3] = "), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },\n";
	s[4] = "), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },\n";
	s[5] = "), XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f) },\n";
	s[6] = "), XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f) },\n";
	s[7] = "), XMFLOAT4(0.0f, 1.0f, 1.0f, 1.0f) }";
	//开始绘制所需的内容
	heng(-3,7,7);
	pie(0,6,5);
	heng(-1,4,4);
	shu(2,3,3);
	shu(-2,3,3);
	heng(-1,1,3);
	//第一个石
	heng(-7,-1,7);
	pie(-4,-2,4);
	heng(-5,-4,5);
	shu(-5,-5,3);
	shu(-1,-5,3);
	heng(-4,-7,3);
	//第二个石
	heng(1,-1,7);
	pie(4,-2,4);
	heng(3,-4,5);
	shu(3,-5,3);
	shu(7,-5,3);
	heng(4,-7,4);
	//写完了
	cout << "共有"<<tot<<"个立方体" << endl << "共需" << 12*tot<<"个图元\n"<<"以及"<<36*tot<<"的顶点数（drawindexed数量）\n";
	change();//更改单元格大小
//	double step = 0.5 / 3;
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < 8; j++){
			cout << "{XMFLOAT3(";
			printf("%.4ff, %.4ff, %.4ff", a[i].first + 2 * step * x[j],a[i].second + 2 * step * y[j],step * z[j]);
//			cout << s[j];
			printf("), XMFLOAT4(%.3ff, %.3ff, %.3ff, %.3ff) }", rd() % 1000 * 0.001,rd() % 1000 * 0.001,rd() % 1000 * 0.001,1.000); //随机生成颜色
			if(j != 7) cout << ",\n";
		}
		if(i == a.size() - 1){
			cout << "\n";
		}
		else cout << ",\n\n";
	}
	cout << "\n\n\n";
	cout << "//正面\n";
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < 6; j++){
			cout << ans[j]+8*i; 
			if(i == a.size() - 1 && j == 35){
				break;
			}
			cout << ", ";
			if(j % 3 == 2){
				cout << "\n";
			}
		}
	}
	cout << "// 左面\n";
	for(int i = 0; i < a.size(); i++){
		for(int j = 6; j < 12; j++){
			cout << ans[j]+8*i; 
			if(i == a.size() - 1 && j == 35){
				break;
			}
			cout << ", ";
			if(j % 3 == 2){
				cout << "\n";
			}
		}
	}
	cout << "// 顶面\n";
	for(int i = 0; i < a.size(); i++){
		for(int j = 12; j < 18; j++){
			cout << ans[j]+8*i; 
			if(i == a.size() - 1 && j == 35){
				break;
			}
			cout << ", ";
			if(j % 3 == 2){
				cout << "\n";
			}
		}
	}
	cout << "// 背面\n";
	for(int i = 0; i < a.size(); i++){
		for(int j = 18; j < 24; j++){
			cout << ans[j]+8*i; 
			if(i == a.size() - 1 && j == 35){
				break;
			}
			cout << ", ";
			if(j % 3 == 2){
				cout << "\n";
			}
		}
	}
	cout << "// 右面\n";
	for(int i = 0; i < a.size(); i++){
		for(int j = 24; j < 30; j++){
			cout << ans[j]+8*i; 
			if(i == a.size() - 1 && j == 35){
				break;
			}
			cout << ", ";
			if(j % 3 == 2){
				cout << "\n";
			}
		}
	}
	cout << "// 底面\n";
	for(int i = 0; i < a.size(); i++){
		for(int j = 30; j < 36; j++){
			cout << ans[j]+8*i; 
			if(i == a.size() - 1 && j == 35){
				break;
			}
			cout << ", ";
			if(j % 3 == 2){
				cout << "\n";
			}
		}
	}
	return 0;
}
