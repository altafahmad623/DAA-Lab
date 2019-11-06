#include<stdio.h>
#include<stdlib.h>
typedef struct Interval
{
    int low, high;
}Interval;
typedef struct ITNode
{
    Interval *i;
    int max;
     struct ITNode *left, *right;
}ITNode;
ITNode * newNode(Interval i)
{
    ITNode *temp;
    temp=(ITNode *)malloc(sizeof(ITNode));
    temp->i = (Interval*)malloc(sizeof(Interval));
    temp->i->low=i.low;
    temp->i->high=i.high;
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
};

ITNode *insert(ITNode *root, Interval i)
{
    if (root == NULL)
        return newNode(i);
    int l = root->i->low;
    if (i.low < l)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);
    if (root->max < i.high)
        root->max = i.high;

    return root;
}

int doOVerlap(Interval i1, Interval i2)
{
    if (i1.low <= i2.high && i2.low <= i1.high)
        return 1;
    return 0;
}

Interval *overlapSearch(ITNode *root, Interval i)
{
    if (root == NULL) return NULL;
    if (doOVerlap(*(root->i), i))
        return root->i;
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
    return overlapSearch(root->right, i);
}

void inorder(ITNode *root)
{
    if (root == NULL) return;
    inorder(root->left);
    printf("[ %d, %d];;max= %d\n",(root->i->low),(root->i->high),(root->max));
    inorder(root->right);
}
int main()
{
    int n;
    int i;
    printf("Enter the number of intervals\n");
    scanf("%d",&n);
    Interval ints[n];
    printf("Enter the interval value(s)\n");
    int x,y;
    for(i=0;i<n;i++)
     {
       scanf("%d%d",&x,&y);
       ints[i].low=x;
       ints[i].high=y;
     }
    ITNode *root = NULL;
    for ( i = 0; i < n; i++)
        root = insert(root, ints[i]);
    printf("Inorder traversal of the given intervals along with the max value of Each:\n");
    inorder(root);
    printf("Enter the interval to search\n");
    scanf("%d%d",&x,&y);
    Interval xx = {x, y};
    printf("Searching for interval [ %d, %d ]",xx.low,xx.high);
    Interval *res = overlapSearch(root, xx);
    if (res == NULL)
       printf("\nNo Overlapping Interval");
    else
        printf( "\nOverlaps with the Interval [%d , %d]",res->low,res->high);
    return 0;
}
