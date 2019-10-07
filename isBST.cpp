bool isBst(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    
    if(root->right!=NULL && minimum(root->right) < root->data)
    {
        return false;
    }
    if(root->left!=NULL && maximum(root->left) > root->data)
    {
        return false;
    }
    
    bool lr = isBst(root->left);
    bool rr = isBst(root->right);
    if(!lr || !rr)
    {
        return false;
    }
    return true;
}


//-------------------------------------------------------------------------------------------


class BSTPair{
    public:
    int min;
    int max;
    bool isBST;
};

BSTPair* isBst(Node* root)
{
    if(root == NULL)
    {
        BSTPair* bp = new BSTPair();
        bp->min = INT_MAX;
        bp->max = INT_MIN;
        bp->isBST = true;
        return bp;
    }
    
    BSTPair* lp = isBst(root->left);
    BSTPair* rp = isBst(root->right);
    BSTPair* mp = new BSTPair();
    
    mp->min = min(root->data, min(lp->min, rp->min));
    mp->max = max(root->data, max(lp->max, rp->max));
    
    mp->isBST = lp->isBST && rp->isBST && root->data > lp->max && root->data < rp->min;
    
    return mp;
}
