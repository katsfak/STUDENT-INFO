#include <iostream>
using namespace std;

class Student
{
private:
    int Am;
    string name;
public:
    void Register()
    {
        cout<<"Insert AM"<<endl;
        cin>>Am;
        cout<<"Insert name"<<endl;
        cin>>name;
    }
    void ShowCredits()
    {
        cout<<"AM: "<<Am<<endl;
        cout<<"Name: "<<name<<endl;
    }
    int Search(string);
    int SearchAM(int);
};

int Student::Search(string a)
{
    if (name==a)
    {
        ShowCredits();
        return 1;
    }
    return 0;
}

int Student::SearchAM(int ab)
{
    if (Am==ab)
    {
        ShowCredits();
        return 1;
    }
    return 0;
}

int main()
{
    cout<<"----STUDENT INFO----"<<endl;
    int st,ep,found=0,am,f=0;
    string Name;
    // Register of students
    cout<<"How many Students you want  to register?"<<endl;
    cin>>st;
    Student* num= new Student[st];
        for (int i = 0; i < st; i++)
            {
                (num+i)->Register();
            }
    do
    {
        //MENU
        cout<<"1.Show Info"<<endl;
        cout<<"2.Search by Name"<<endl;
        cout<<"3.Search by Am"<<endl;
        cout<<"4.Exit"<<endl;
        do
        {
            cout<<"Input choice"<<endl;
            cin>>ep;
            if (ep<=0 || ep>=5) //Check for User Input if the choice is 1-4
            {
                cout<<"Wrong input insert again"<<endl;
            }
        } while (ep<=0 || ep>=5);

       	
		if(ep==1) //Show Info
		{
			    
                for (int i = 0; i < st; i++)
                {
                    (num+i)->ShowCredits();

                }
            
		}
		if(ep==2) //Search by Name
		{
			
                cout<<"Insert Name of Student"<<endl;
                cin>>Name;
                
                for (int i = 0; i < st; i++)
                {
                    found=(num+i)->Search(Name);
                    if(found==1)
                        {
                            break;
                        }
                }
                if (found==0)
                {
                    cout<<"Not found Student"<<endl;
                }
            
		}
        if(ep==3) //Search by Am
        {
            	cout<<"Insert AM of Student"<<endl;
                cin>>am;
                
                for (int i = 0; i < st; i++)
                {
                    f=(num+i)->SearchAM(am);
                        if(f==1)
                        {
                            break;
                        }
                }
                if (f==0)
                {
                cout<<"Not found Student"<<endl;
                
                }
		}
		if(ep==4) //Exit
		{
            cout<<"----EXIT----"<<endl;
				break;
		}
    } while (ep!=4);
    delete num; //free mem
    return 0;
}
