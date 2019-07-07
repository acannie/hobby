#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <direct.h>
using namespace std;

void fwriting(FILE *fi){
    fprintf(fi, "/*  */\n");
    fprintf(fi, "/*  */\n");
    fprintf(fi, "\n");
    fprintf(fi, "#include <iostream>\n");
    fprintf(fi, "#include <string>\n");
    fprintf(fi, "#include <algorithm>\n");
    fprintf(fi, "#include <cmath>\n");
    fprintf(fi, "using namespace std;\n");
    fprintf(fi, "\n");
    fprintf(fi, "int main()\n");
    fprintf(fi, "{\n");
    fprintf(fi, "\treturn 0;\n");
    fprintf(fi, "}\n");

    fclose(fi);
}

int main()
{
    string folder_name;
    FILE *fi;
    char filename[100];

    /* フォルダ名読み込み */
    cout << "Input folder name --> ";
    cin >> folder_name;

    /* フォルダ生成 */
    if (_mkdir(folder_name.c_str()) == 0)
    {
        printf("succeed to make dir.\n");
    }
    else
    {
        printf("failed to make dir.\n");
    }

    /* cppファイル生成 */
    sprintf(filename, "%s/%s.cpp", folder_name.c_str(), "full_search");
    fi = fopen(filename, "w");

    if (fi == NULL)
    {
        fprintf(stderr, "error!\n");
        exit(1);
    }

    fwriting(fi);

    sprintf(filename, "%s/%s.cpp", folder_name.c_str(), "see_detail");
    fi = fopen(filename, "w");

    if (fi == NULL)
    {
        fprintf(stderr, "error!\n");
        exit(1);
    }

    fwriting(fi);

    return 0;
}