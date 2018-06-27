# include<iostream>
# include<iomanip>
# define N  20   //评委的人数最多为20
# define M  50   //参赛选手的人数最多为50

using namespace std;

float CountAthleteScore(int , float ave, int n, float s[], int m);
void Sort(float a[], int n);
void Print(float a[], int n,int bh[]);
float b[M];
int bh[M];

int main()
{
    int i=0,n,m,r,t=0;
    float s[N],a[M],ave=0.0,sum=0.0;
    char name[20],sex[2];
    cout<<"******欢迎使用评分系统******"<<endl;
    cout<<"   请输入评委个数（>=3)：";
    cin>>n;
    cout<<"   请输入参赛选手个数(>=2)：";
    cin>>m;
    cout<<endl;
    
    
    for(i=0;i<m;i++)
    {cout<<"       选手参赛中     "<<endl;
        cout<<"       编号为：";
        cin>>bh[i];
        a[r++]=CountAthleteScore(bh[i], ave, n,s, m);
    }
    
    
    
    cout<<m<<"这位选手的平均成绩分别是："<<endl;
    for(r=0;r<m;r++)
        cout<<a[r]<<"  ";
    cout<<endl;
    Sort(a, m);
    Print( a, n,bh);
    return 0;
    
    /*int num;
    ifstream fin("/Users/a20161104582/Desktop/match points/input.csv");
    string line;
    while (getline(fin, line))
    {
        cout <<"选手信息："<<line<<endl;//整行输出
        istringstream sin(line);
        vector<string> fields;//声明一个字符串向量
        string field;
        while (getline(sin,field,','))
        {
            fields.push_back(field);
        }
        string name=Trim(fields[0]);
        string sex=Trim(fields[0]);
        //cout<<"处理后的字符串："<<name<<"\t"<<sex<<"\t"<<num<<endl;
    }
    return EXIT_SUCCESS;*/

}

float CountAthleteScore(int , float ave, int n, float s[], int m)
{
    int j,k,r=0;
    static int w=0;
    float t,sum=0.0;
    ave=0.0;
    
    cout<<"请输入评委的评分："<<endl;
    for(k=0;k<n;k++)//不加花括号会出现错误
    {
        cout<<endl;
        cout<<"输入第"<<k+1<<"位评委给分: ";
        cin>>s[k];
        if((s[k]>10)||(s[k]<0))
        {
            cout<<"第"<<k+1<<"位评委输入时出现错误,请重新输入"<<endl;
            k--;
        }
    }
    
    
    
    for(k=0;k<n-1;k++)     //对每位选手的成绩排序，以便去掉最低分和最高分;
    {
        for(j=k+1;j<n;j++)
            if(s[k]<s[j])
            {
                t=s[k];
                s[k]=s[j];
                s[j]=t;
            }
    }
    cout<<"对评委给分由高到低进行排序："<<endl;
    for(k=0;k<n;k++)
        cout<<s[k]<<"  ";
    cout<<endl;
    cout<<"去掉一个最高分"<<s[0]<<",一个最低分"<<s[n-1]<<",后的结果："<<endl;
    for(k=0;k<n-2;k++)
        
    {
        cout<<s[k+1]<<"  ";
        sum=sum+s[k+1];
    }
    cout<<endl;
    ave= sum/float(n-2);
    b[w++]=ave;
    cout<<"该选手平均分="<<ave<<endl;
    return ave;
    cout<<"*************************"<<endl;
    
}
void Sort(float a[],  int m)
{
    
    int j;
    int r;
    float t;
    for(r=0;r<m-1;r++)     //对平均成绩进行排序;
    {
        for(j=0;j<m-1-r;j++)
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    }
    cout<<"由高到低排序后的成绩为："<<endl;
    for(r=0;r<m;r++)
        cout<<a[r]<<"  ";
    cout<<endl;
    cout<<"************************"<<endl;
    cout<<"************************"<<endl;
}


void Print(float a[], int m,int bh[])
{
    int i;
    if((a[0]!=a[1])&&a[1]!=a[2])
        
    {
        if(m>2){
            cout<<setw(18)<<"编号"<<setw(15)<<"成绩"<<endl;
            cout<<"冠军:   ";
            
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[0]<<endl;
            cout<<"亚军：  ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[1]<<endl;
            cout<<"季军：  ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[2])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[2]<<endl;
        }
        else{
            
            cout<<setw(18)<<"编号"<<setw(15)<<"成绩"<<endl;
            cout<<"冠军：   ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(13)<<a[0]<<endl;
            cout<<"亚军：   ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(13)<<a[1]<<endl;
        }
    }
    
    else if((a[0]==a[1])&&(a[1]!=a[2]))
    {
        cout<<"**两位选手并列第一"<<endl;
        if(m>2)
        {
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"  ";
            }
            cout<<"成绩为："<<a[1]<<endl;
            cout<<"亚军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[2])
                    break;
            }
            cout<<bh[i];
            cout<<"成绩为："<<a[2]<<endl;
            
        }
        else
        {
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<bh[i];cout<<"   ";
            cout<<"成绩为："<<a[1]<<endl;
        }
    }
    else if((a[0]!=a[1])&&(a[1]==a[2]))
    {
        if(m>2)
        {
            cout<<"**几位选手并列第二"<<endl;
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<"冠军   编号为："<<bh[i];
            cout<<"成绩为："<<a[0]<<endl;
            
            cout<<"亚军   编号为：";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    cout<<bh[i]<<"   ";
            }
            
            cout<<"成绩为："<<a[2]<<endl;
        }
        else
        {
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<"冠军   编号为："<<bh[i]<<"   ";}
            cout<<"成绩为："<<a[0]<<endl;
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    cout<<"亚军   编号为："<<bh[i]<<"   ";
            }
            cout<<"成绩为："<<a[1]<<endl;
        }
    }
    else if((a[0]==a[1])&&(a[1]==a[2]))
    {
        if(m>2)
        {
            cout<<"**几位选手并列第一"<<endl;
            cout<<"冠军   编号为:";
            
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"   ";
            }
            cout<<"成绩为："<<a[0]<<endl;
            
        }
        else
        {
            cout<<"**两位选手并列第一"<<endl;
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"   ";
            }
            
        }
    }
}
/*string Trim(string& str)
{
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n")+1);
    return str;
}*/
    

   /* int num;
    ifstream fin("/Users/a20161104582/Desktop/match points/input.csv");
    string line;
    while (getline(fin, line))
    {
        cout <<"选手信息："<<line<<endl;//整行输出
        istringstream sin(line);
        vector<string> fields;//声明一个字符串向量
        string field;
        while (getline(sin,field,','))
        {
            fields.push_back(field);
        }
        string name=Trim(fields[0]);
        string sex=Trim(fields[0]);
        //cout<<"处理后的字符串："<<name<<"\t"<<sex<<"\t"<<num<<endl;
    }
    return EXIT_SUCCESS;*/
