#include <iostream>

using namespace std;

typedef struct node
{
    struct node* child[26];
    char c;
    bool isEnd;
    bool isRoot;

}trie;

//int ascii_alphabet[26] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z'};
char alphabet[26] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z'};

void insert_str_into_trie(trie* root , string str , int size)
{
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < 26;j++)
        {
            if(str[i] == alphabet[j])
            {
                if(root->child[j] == NULL)
                {
                    root->child[j] = new trie;
                    root->child[j]->c = alphabet[j];
                    root = root->child[j];
                    for(int i = 0;i < 26;i++)
                    {
                        root->child[i] = NULL;
                        root->isRoot = 0;
                    }
                    break;
                }
                else
                {
                    root = root->child[j];
                }
            }


        }
    }
}


int shortest_path(string s1 , string s2 , trie* root , int n , int m)
{
    trie* temp = root;
    int counter1 = 0;
    int counter2 = 0;
    int flag1 = 0;
    int flag2 = 0;

    for(int i = 0;i < n;i++)
    {
        if(s1[i] == s2[i] && flag1 == 0)
        {
            root = root->child[s1[i] - 97];
            continue;
        }
        else
        {
            flag1 = 1;
            for(int j = 0;j < 26;j++)
            {
                if( root->child[j] != NULL && root->child[j]->c == s1[i] )
                {
                    counter1++;
                    root = root->child[j];
                    break;

                }
            }
            if(root == NULL)
            {
                break;
            }
        }

    }


    root = temp;
    for(int i = 0;i < m;i++)
    {
        if(s1[i] == s2[i] && flag2 == 0)
        {
            root = root->child[s2[i] - 97];
            continue;
        }
        else
        {
            flag2 = 1;
            for(int j = 0;j < 26;j++)
            {
                if( root->child[j] != NULL && root->child[j]->c == s2[i] )
                {
                    counter2++;
                    root = root->child[j];
                    break;

                }
            }
            if(root == NULL)
            {
                break;
            }
        }

    }

    return counter1 + counter2;





}
int main()
{
    trie root;
    root.isRoot = 1;
    root.isEnd = 0;
    root.c = '!';

    for(int i = 0;i < 26;i++)
    {
        root.child[i] = NULL;
        root.isRoot = 0;
    }

    int n  = 0 , m = 0;
    string s1 , s2;

    cin >> n >> s1;
    cin >> m >> s2;

    insert_str_into_trie(&root , s1 , n);
    insert_str_into_trie(&root , s2 , m);
    int result = shortest_path(s1 , s2 , &root , n , m);
    printf("%d",result);


    return 0;
}



