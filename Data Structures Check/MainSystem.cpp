#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int compareOutput(){
    char ansOutput[100000] = {0}, testOutput[100000] = {0}, c;
    int ansLen = 0, testLen = 0;

    //-------------------提取答案輸出-------------------------
    FILE *fp = fopen("Answer\\output.txt","r");

    while((c = fgetc(fp)) != EOF){
        ansOutput[ansLen++] = c;
    }
    fclose(fp);
    

    //-------------------提取受試輸出-------------------------
    fp = fopen("Tester\\output.txt","r");
    while((c = fgetc(fp)) != EOF){
        testOutput[testLen++] = c;
    }
    fclose(fp);

    //--------------------開始比對----------------------------

    int i = 0, j = 0, status = 1;
    while(i < ansLen && j < testLen){
        if(ansOutput[i] != testOutput[j]){
            if(ansOutput[i] == ' ' || ansOutput[i] == '\n'){
                status = 0;
                i++;
            }
            else if(testOutput[j] == ' ' || testOutput[j] == '\n'){
                status = 0;
                j++;
            }
            else return -1;
        }
        else {
            i++;
            j++;
        }
    }

    while(i < ansLen){
        if(ansOutput[i] != ' ' && ansOutput[i] != '\n')return -1;
        i++;
    }

    while(j < testLen){
        if(testOutput[j] != ' ' && testOutput[j] != '\n')return -1;
        j++;
    }

    return status;
}

int main(int argc, char const *argv[])
{
    if(argc != 2){
        printf("輸入格式錯誤，請確認\n\n");
        return 0;
    }

    string testInput(argv[1]);
    string testPath = "g++ -std=c++11 Tester\\TesterCode\\" + testInput + " -o Tester\\tester";

    int ansCompile = system("g++ -std=c++11 Answer\\AnswerCode\\Miderterm2018_11.cpp -o Answer\\answer");        //將解答編譯
    int testCompile = system(testPath.c_str());       //將受試編譯

    if(ansCompile != 0){
        printf("解答編譯未過，請確認Answer資料夾之程式碼是否寫對");
        return 0;        
    }

    if(testCompile != 0){
        printf("受試編譯未過，請確認Tester資料夾之程式碼是否寫對");
        return 0;    
    }

    for(int i = 1; i <= 3; i++){
        printf("-----------------------------------正在執行第%d筆測資-----------------------------------\n\n",i);
        string inputNum(to_string(i));
        string ansRunPath = "Answer\\answer < input\\input" + inputNum + ".txt > Answer\\output.txt";
        string testRunPath = "Tester\\tester < input\\input" + inputNum + ".txt > Tester\\output.txt";

        printf("正在執行answer.exe.................\n\n");
        int ansRun = system(ansRunPath.c_str());
        if(ansRun != 0){
            printf("answer 執行錯誤\n");
            return 0;
        }
        else printf("已執行完畢answer.exe...............\n\n");



        printf("正在執行tester.exe.................\n\n");
        int testRun = system(testRunPath.c_str());
        if(testRun != 0){
            printf("tester 執行錯誤\n");
            return 0;
        }
        else printf("已執行完畢tester.exe...............\n\n");

        int compareResult = compareOutput();

        if(compareResult == 1)printf("Accept\n\n");
        else if(compareResult == -1)printf("Wrong Answer\n\n");
        else printf("格式錯誤\n\n");

        if(compareResult != 1)system("pause");
    }
}