#include <iostream>
#include <cctype>

using namespace std;

/*JHTMLLET*/
int main()
{
    char znak;
    bool html = false;
    while(cin.read(&znak,sizeof(char)))
    {

        if(znak=='<'){
            html = true;
        }else if(znak=='>'){
            html = false;
        }else{
            if(html){
                znak = toupper(znak);
            }
        }
        cout << znak;
    }
    return 0;
}
