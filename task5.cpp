#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

class Equation
{
    public:
    Equation()
    {

    }
    virtual void setVariables()=0;
    virtual void solveEquation()=0;
};
class myTask : public Equation
{
    public:

    vector<string>equationList;
    vector<int>a;vector<int>b;vector<int>c;vector<int>d;


    myTask(vector<string>&equationList):Equation()
    {
        this->equationList=equationList;
    }
    
    int solveDeterminant(vector<vector<int>>matrix)
    {
        int a1,b1,c1,a2,b2,c2,a3,b3,c3;
        a1=matrix[0][0];
        b1=matrix[0][1];
        c1=matrix[0][2];
        a2=matrix[1][0];
        b2=matrix[1][1];
        c2=matrix[1][2];
        a3=matrix[2][0];
        b3=matrix[2][1];
        c3=matrix[2][2];
        
        
        int answer=a1*(b2*c3-c2*b3)-b1*(a2*c3-c2*a3)+c1*(a2*b3-b2*a3);
        return answer;
    }
    void solveEquation()
    {
        vector<vector<int>>D;
        vector<vector<int>>DX;
        vector<vector<int>>DY;
        vector<vector<int>>DZ;
        

        D.pb(this->a);
        D.pb(this->b);
        D.pb(this->c);

        DX.pb(this->d);
        DX.pb(this->b);
        DX.pb(this->c);

        DY.pb(this->a);
        DY.pb(this->d);
        DY.pb(this->c);

        DZ.pb(this->a);
        DZ.pb(this->b);
        DZ.pb(this->d);

       


        if(solveDeterminant(D)==0)
        {
            cout<<"Non-Unique Solution"<<endl;
        }
        else
        {
        
            float x=solveDeterminant(DX)/solveDeterminant(D);
            float y=solveDeterminant(DY)/solveDeterminant(D);
            float z=solveDeterminant(DZ)/solveDeterminant(D);

            cout<<"The answer is "<<x<<" "<<y<<" "<<z<<endl;
        }
    }
    void setVariables()
    {
       
        for(int i=0;i<this->equationList.size();i++)
        {
            
            for(int j=0;j<this->equationList[i].size();j++)
            {
                
                if(this->equationList[i][j]=='=')
                {
                    int neg=0;
                    string num="";
                    
                    for(int k=j+1;k<this->equationList[i].size();k++)
                    {
                       
                        if(this->equationList[i][k]=='-')
                        {
                           
                            neg=1;
                        }
                        else
                        {
                           num.pb(this->equationList[i][k]); 
                        }
                    }
                   
                    int x=stoi(num);
                    if(neg==1)
                    {
                        x=-x;
                    }
                  
                    this->d.pb(x);
                    
                }
                if(this->equationList[i][j]=='x')
                {
                   
                    int flag=0;
                    string number="";
                    int neg=0;
                    for(int k=j-1;k>=0;k--)
                    {
                       //Gone once into loop
                        if(this->equationList[i][k]=='+')
                        {
                            break;
                        }
                        else if(this->equationList[i][k]=='-')
                        {
                            neg=1;
                            break;
                        }
                        else
                        {
                            flag=1;
                            number.pb(this->equationList[i][k]);
                        }
                    }
                    if(flag==0)
                    {
                        number.pb('1');
                    }
                    reverse(number.begin(),number.end());
                    int x=stoi(number);
                    if(neg==1)
                    {
                        x=-x;
                    }
                    
                    this->a.pb(x);
                }

                if(this->equationList[i][j]=='y')
                {
                    
                    int flag=0;
                    string number="";
                    int neg=0;
                    for(int k=j-1;k>=0;k--)
                    {
                       //Gone once into loop
                        if(this->equationList[i][k]=='+')
                        {
                            break;
                        }
                        else if(this->equationList[i][k]=='-')
                        {
                            neg=1;
                            break;
                        }
                        else
                        {
                            flag=1;
                            number.pb(this->equationList[i][k]);
                        }
                    }
                    if(flag==0)
                    {
                        number.pb('1');
                    }
                    reverse(number.begin(),number.end());
                    int x=stoi(number);
                    if(neg==1)
                    {
                        x=-x;
                    }
                  
                    this->b.pb(x);
                }

                else if(this->equationList[i][j]=='z')
                {
                  
                    int flag=0;
                    string number="";
                    int neg=0;
                    for(int k=j-1;k>=0;k--)
                    {
                       //Gone once into loop
                        if(this->equationList[i][k]=='+')
                        {
                            break;
                        }
                        else if(this->equationList[i][k]=='-')
                        {
                            neg=1;
                            break;
                        }
                        else
                        {
                            flag=1;
                            number.pb(this->equationList[i][k]);
                        }
                    }
                    if(flag==0)
                    {
                        number.pb('1');
                    }
                    reverse(number.begin(),number.end());
                    int x=stoi(number);
                    if(neg==1)
                    {
                        x=-x;
                    }
                    //cout<<"HelloZ"<<endl;
                    this->c.pb(x);
                }
            }
        }
    }


    void printVariables()
    {
        cout<<"A"<<endl;
        for(int i=0;i<this->a.size();i++)
        {
            cout<<this->a[i]<<" ";
        }
        cout<<endl;

        cout<<"B"<<endl;
        for(int i=0;i<this->b.size();i++)
        {
            cout<<this->b[i]<<" ";
        }
        cout<<endl;
        cout<<"C"<<endl;
        for(int i=0;i<this->c.size();i++)
        {
            cout<<this->c[i]<<" ";
        }
        cout<<endl;

        cout<<"D"<<endl;
        for(int i=0;i<this->d.size();i++)
        {
            cout<<this->d[i]<<" ";
        }
        cout<<endl;
    }
};
class Parse
{
    public:
    static void equationType(vector<string>&equationList,vector<Equation*>&equationObject)
    {
        if(equationList.size()==3)
        {
            Equation* object = new myTask(equationList);
            equationObject.pb(object);
        }
    }
};
int32_t main()
{
    vector<Equation*>equationObject;
    vector<string>equationList;
    while(1)
    {
        string x;  //ALL 3 EQUATION'S TAKEN AT ONCE
        cin>>x;
        if(x=="##")
        {
            break;
        }
        else
        {
            stringstream check(x);
            string intermediate;
            while(getline(check,intermediate,';'))
            {
                equationList.pb(intermediate);
            }    
            
        }  
    }
    
    Parse::equationType(equationList,equationObject);
    
    for(int i=0;i<equationObject.size();i++)
    {
        equationObject[i]->setVariables();
        equationObject[i]->solveEquation();
    }
}
