#include<iostream>
#include<cmath>

using namespace std;
const int M=2000;


class PointX {
public:
    int operator<=(PointX a)const;
    int ID; //点编号
    float x,y; //点坐标
};

int PointX::operator<=(PointX a) const { return x <= a.x; }

template <class Type>
inline float dis(const Type& u,const Type& v);

int main()
{
    cout << "胡彬梅 20164507" << endl;
    int length;

    cout<<"请输入点对数：";
    cin>>length;

    PointX X[M];
    cout<<"请输入所有点对："<<endl;

    for(int i=0;i<length;i++)
    {
        cin >> X[i].x >> X[i].y;
    }

    float dmin;//最小距离
    float d;//距离
    float dminX1, dminY1, dminX2, dminY2;
    dminX1 = dminY1 = dminX2 = dminY2 = 0;
    d = dmin = dis(X[0],X[1]);

    for(int i=0; i<length; i++)
    {
        for(int j=i+1; j<length; j++)
        {
            d = dis(X[i],X[j]);
            if(d<=dmin)
            {
                dmin = d;
                dminX1 = X[i].x;
                dminY1 = X[i].y;
                dminX2 = X[j].x;
                dminY2 = X[j].y;
            }
        }
    }

    cout<<endl;
    cout<<"最邻近点对为：("<<dminX1<<","<<dminY1<<")和("<<dminX2<<","<<dminY2<<") "<<endl;
    cout<<"最邻近距离为： "<<dmin<<endl;
    return 0;
}

template <class Type>
inline float dis(const Type& u,const Type& v)
{
    float dx=u.x-v.x;
    float dy=u.y-v.y;
    return sqrt(dx*dx+dy*dy);
}
