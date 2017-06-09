#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

template<class T>
class BSTNode {
    public:
    BSTNode(){
        left = right =0;
    }
    BSTNode(T data, BSTNode<T> *l=0,BSTNode <T>*r=0){
        el=data;
        left=l;
        right =r;
    }
   T el;
    BSTNode<T> *left, *right;
};
template <class T>
class BST {
    public:
    BST() {
        root =0;
    }
    void visit(BSTNode <T>*p){
        cout<<p->el<<" ";
    }
    void BF(){
        BSTNode<T> *t=root;
        stack<BSTNode<T>*> S;
        while(1){
            while(t){
                visit(t);
                S.push(t);
                t=t->left;
            }
            if(S.empty())break;
            t=S.top();S.pop();
            t=t->right;
        }
    }
    void in(){
        in(root);
    }
    void insert(T el){
        if(root==0) root = new BSTNode<T>(el);
        else {
            BSTNode <T>*p=root, *prev=0;
            while(p!=0){
                prev=p;
                if(el>p->el) 
                    p=p->right;
                else 
                    p=p->left;
            }
            if(prev->el >el) prev->left = new BSTNode <T>(el);
            else prev->right = new BSTNode <T>(el);
        }
    } 
    bool isBSTone(BSTNode<T>*root){
        if(!root) return 1;
        if(root->el>findmax(root->left)) return 0;
        if(root->el<findmin(root->right)) return 0;
        if(!isBSTone(root->left) || !isBSTone(root->right)) return 0;
    }
    int findmax(BSTNode<T>*root){
        if(root==0) return 0;
        else{
            int a = findmax(root->left);
            int b = findmax(root->right);
            int c = a>b?a:b;
            return (root->el>c)?root->el:c;
        }
    }
    int findmin(BSTNode<T>*root){
        if (root==0) return 1320;
        else{
            int a = findmin(root->left);
            int b = findmin(root->right);
            int c = a<=b?a:b;
            return (root->el>c)?c:root->el;
        }
    }
 
    bool isBST(BSTNode<T>*root, int prev){
        if(root==0) return 1;
        if(!isBST(root->left, prev)) return 0;
        if(root->el<prev) return 0;
        prev = root->el;
        return isBST(root->right, prev);
    }
    void insertBT(int el){
        if(root==0) root = new BSTNode<T>(el);
        else {
            queue<BSTNode <T>*>q;
            BSTNode <T>*p=root;
            if(p!=0){
                q.push(p);
                while(!q.empty()){
                    p=q.front();
                    q.pop();
                    if(p->left==0) {
                        p->left  = new BSTNode<T>(el);
                        break;
                        //while(!q.empty()) q.pop();
                    }
                    else q.push(p->left);
                    if(p->right!=0) q.push(p->right);
                    else {
                        p->right= new BSTNode <T>(el);
                        break;
                        //while(!q.empty()) q.pop();
                    }
                }
            }
        }
    }
    void BFS(){
        if(root==0) cout<<"Empty Tree"<<endl;
        else {
            BSTNode <T>*p=root;
            queue<BSTNode<T>*>q;
            if(p!=0){
                q.push(p);
                while(!q.empty()){
                    p=q.front();
                    visit(p);
                    q.pop();
                    if(p->left!=0) q.push(p->left);
                    if(p->right!=0) q.push(p->right);
                }
            }
        }
    }
    int antiBFS(){
        int count=0;
        BSTNode <T>*p=root;
        queue<BSTNode<T>*>q;
        stack<BSTNode<T>*>s;
        if(p!=0){
            q.push(p);
            while(!q.empty()){
                p=q.front();
               // s.push(p);
                q.pop();
                
                if(p->left!=0) {
                    q.push(p->left);
                    if(p->right!=0) count++;
                }
                if(p->right!=0) {
                    q.push(p->right);
                    if(p->left!=0) count++;
                }
            } 
            return count/2;
        }
    }
    
    void iterpostorder () {
        stack<BSTNode<T>*> s;
        BSTNode<T>*p =root, *q= root;
        while(p!=0){
            for(;p->left!=0;p=p->left) s.push(p);
        }
        while(p->right==0||p->right==q){
            visit(p);
            q=p;
            if(s.empty()) return;
            p=s.top();
            s.pop();
        }
        s.push(p);
       p=p->right;
    }
    int sum(BSTNode<T>* root){
        if (root==NULL) return 0;
        else return root->el + sum(root->left) + sum(root->right);
    }
    
    void path(BSTNode<T>*root, BSTNode<T>*paths[], int pathlen){
        if(root==0) return;
        paths[pathlen] = root->el;
        pathlen++;
        if(root->left==0&&root->right==0) printAr(paths, pathlen);
        else{
                
        }
        
        
    }
    int maxsum(){
        BSTNode<T>*p=root;
        queue<BSTNode<T>*>q;
        int maxSum=0;
        int currentSum=0;
        int level=0;
        if(p!=0){
            q.push(p);
            q.push(NULL);
            while(!q.empty()){
                p=q.front();
                q.pop();
                if(p==0){
                    if(currentSum>maxSum){
                        maxSum = currentSum;
                    }
                    currentSum=0;
                    if(!q.empty()) q.push(NULL);
                    level++;
                }
                else{
                    currentSum+=p->el;
                    if(p->left!=0) q.push(p->left);
                    if(p->right!=0) q.push(p->right);
                }
            }
        }
        return maxSum;
        
    }
    bool search(BSTNode<T>*root, int el){
        if(root){
            if(root->el==el) return 1;
            else{
                return search(root->left,el)||search(root->right,el);
            }
        }
    }
      
    BSTNode<T>* leastcommon(BSTNode<T>*root, BSTNode<T>*a, BSTNode<T>*b){
        BSTNode<T>* left, *right;
        if(root==NULL) return root;
        if(root==a||root==b) return root;
        left = leastcommon(root->left, a, b);
        right = leastcommon(root->right,a,b);
        if(left&&right) return root;
        else return left?left:right;
    }
    int dia(BSTNode<T>*root){
        if(root==0) return 0;
        else {
            int a = dia(root->left);
            int b = dia(root->right);
            int d = a>b?a:b;
            int c = heightT(root->left) + heightT(root->right) + 1;
            return c>d?c:d;
        }
    }
    int heightT(BSTNode<T>*root) {
        if (root==0) return 0;
        else return (heightT(root->left)>heightT(root->right))? heightT(root->left) +1 : heightT(root->right)+1;
    }

    void mirror(BSTNode<T>*root){
        if(root==NULL) ;
        else{
           BSTNode<T>*p=root;
                    if(p->left!=0) mirror(p->left);
                    if(p->right!=0) mirror(p->right);
                    BSTNode<T>*tmp = p->left;
                    p->left=p->right;
                    p->right=tmp;
                    
                }
            }
        
    
    bool checkMirror(BSTNode<T>*a, BSTNode<T>*b){
        if(a==0&&b==0) return 1;
        else if(a==0||b==0) return 0;
        else{
            if(a->el==b->el){
                return checkMirror(a->left, b->right) && checkMirror(a->right, b->left);
            }
            else return 0;
        }
    }
    
    int height(BSTNode<T>* root){
        //int t=0;
        if(root==NULL) return 0;
        //else if(root->left==0&&root->right==0) return ++t;
        else{
            int m1 = height(root->left);
            int m2 = height(root->right);
            return (m1>m2)?m1+1:m2+1;
        }
    }
    
    int diameter(BSTNode<T>*root){
        if(root==0) return 0;
        else {
            int a = diameter(root->left);
            int b = diameter(root->right);
            return (a>b)?a+1:b+1;
        }
    }
    bool ident(BSTNode<T>* root1, BSTNode<T>* root2){
        if (root1==NULL && root2==NULL) return 1;
        else if(root1==NULL||root2==NULL) return 0;
        else{
            ident(root1->left, root2->left) && ident(root1->right, root2->right);
        } 
    }
    int heightRecur(BSTNode<T>*root){
        queue<BSTNode<T>*> q;
        BSTNode<T>*p=root;
        int level = 0;
        if(p!=0){
            q.push(p);
            q.push(NULL);
            while(!q.empty()){
                p=q.front();
                q.pop();
                if(p==NULL){
                    level++;
                    if(!q.empty()) q.push(NULL);
                }
                else{
                  if(p->left!=0) q.push(p->left);
                  if(p->right!=0) q.push(p->right);
               }
            }
        }
        return level;
    }
    
    bool particularSum(BSTNode<T>* root, int sum){
        if(!root) return (sum==0);
        else {
            int remsum;
            if(sum!=0) remsum= sum - root->el;
            
            if((root->left&&root->right)|| (!root->left&&!root->right)) return (particularSum(root->left, remsum)|| particularSum(root->right, remsum));
            else if(root->left) return particularSum(root->left, remsum);
            else   return particularSum(root->right, remsum);
            
        }
        
    }///
    
    int size(BSTNode<T>*p){
        int t = 0;
        if(p==NULL) return 0;
        else {
            return 1+size(p->left)+size(p->right);
        }
    }
    
    void zigzag(){
        int n = size(root);
        T ar[n];
        int k=1;
        int q=1;
        std::stack<BSTNode<T>*> s1, s2;
        s1.push(root);
        ar[0]=root->el;
        while(!s1.empty()||!s2.empty()){
            if(k==1){
                while(!s1.empty()){
                    BSTNode<T>*p=s1.top();
                    s1.pop();
                    if(p->right!=0) {
                        s2.push(p->right);
                        ar[q] = p->right->el;
                        q++;//cout<<q<<" ";
                    }
                    if(p->left!=0) {
                        s2.push(p->left);
                        ar[q] = p->left->el;
                        q++;//cout<<q<<" ";
                    }
                }k=2;
            }
            else {
                while(!s2.empty()){
                    BSTNode<T>*p=s2.top();
                    s2.pop();
                    if(p->left!=0){
                        s1.push(p->left);
                        ar[q] = p->left->el;
                        q++;//cout<<q<<" ";
                    }
                    if(p->right!=0) {
                        s1.push(p->right);
                        ar[q] = p->right->el;
                        q++;//cout<<q<<" ";
                    }
                }   k=1; 
            }
        }
        for(int i=0;i<n;i++) cout<< ar[i]<<" ";
        
        
    }
    
  
    
    stack<BSTNode<T>*> q;
    void ances(BSTNode<T>*p, T el){
        //BSTNode<T>*p=root;
        q.push(p);
        while(!q.empty()){
            if(p->el!=el){
                
                if(p->left) ances(p->left, el);
                if(!p->right&&!p->left) {
                    q.pop();
                    p = q.top();
                    q.pop();
                    p->left=NULL;
                    ances(p,el);
                }        
                while(!p->left&&p->right&&p->right->el!=el) 
                {
                    //if(p->right) 
                    ances(p->right, el);
                }
            } 
            else {
                visit(p);
                while(!q.empty()) {
                    BSTNode<T>* a = q.top();
                    visit(a);
                    q.pop();
                }
               
            }
             break;
        }
    }

    
    
    int sumLevelRecur(BSTNode<T>*root){
        queue<BSTNode<T>*> q;
        BSTNode<T>*p=root;
        int level = 0;
        int maxLevel;
        int currenSum=0;int maxSum=0;
        if(p!=0){
            q.push(p);
            q.push(NULL);
            while(!q.empty()){
                p=q.front();
                q.pop();
                if(p==NULL){
                    level++;
                    if(currenSum>maxSum) {
                        maxSum = currenSum;
                        maxLevel= level;}
                    if(!q.empty()) q.push(NULL);
                                    currenSum =0;
                }
                else{
                     currenSum += p->el;
                  if(p->left!=0) q.push(p->left);
                  if(p->right!=0) q.push(p->right);
               }
              
            }
        }
        return maxSum;
    }
    int heigh(BSTNode<T>*p){
        if(p==NULL) return 0;
        else return max(height(p->left), height(p->right)) + 1;
    }
    int diamete(BSTNode<T>*p){
        if(p==NULL) return 0;
        else {
            int l = height(p->left);
            int r = height(p->right);
            return max (l+r+1, max(diameter(p->left), diameter(p->right)));
        }
    }
    int maxtt(BSTNode<T>*p){
        if(p==0) return 0;
        int a = max(p->left);
        int b = max(p->right);
        int c = a>b?a:b;
        return p->el > c ? p->el:c;
    }
    bool ident(BSTNode<T>* ar, BSTNode<T> br){
        //BSTNode<T>* ar = a.root;
        //BSTNode<T>* br = b.root;
        if(ar!=0&&br!=0&&ar->el==br->el){
            ident(ar->left, br->left);
        }
        else return 0;
    }
    bool childSum(BSTNode<T>*root){
        if (root->left==0&&root->right==0) return 1;
        else if(!root->left) return root->el==root->right->el &&  childSum(root->left)&&childSum(root->right);
        else if(!root->right) return root->el==root->left->el &&  childSum(root->left)&&childSum(root->right);
        else return(root->el = root->left->el + root->right->el) && childSum(root->left)&&childSum(root->right);
    }
    void inordIT(){
        stack<BSTNode<T>*> s;
        while(1){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            if(s.empty()) break;
            root = s.top();
            s.pop();
            visit (root);
            root = root->right;
        }
    }
    bool searchNR(int el){
        stack<BSTNode<T>*> s;
        BSTNode<T>*p =root;
        if(p->el==el) return true;
       else {
        if(p!=0){
            s.push(p);
            while(!s.empty()){
                p = s.topt();
                s.pop();
                if(p->el==el){ //cout<<" "<<s.top()<<" ";
                return true;
                break;}
                if(p->right) s.push(p->right);
                if(p->left) s.push(p->left);
            }
            if(s.empty()) return 0;
        }
        }
    }
    int maxWidth(){
        BSTNode<T>*p = root;
        int maxwidth = 0;
        int width = 0;
        queue<BSTNode<T>*> q;
        if(p!=0){
            q.push(p);
            q.push(NULL);
            while(!q.empty()){
                p =q.front();
                q.pop();
                if(p==NULL){
                    maxwidth = (maxwidth>width)?maxwidth:width;
                    if(!q.empty()) q.push(NULL);
                    width=0;
                }
                else {
                    width++;
                    if(p->left!=0) q.push(p->left);
                    if(p->right!=0) q.push(p->right);
                }
            }
        }return maxwidth;
        
    }
    bool ifRtoLsum(BSTNode<T>*root, int l){
        if (root==NULL&&l==0) return 1;
        else if(root==NULL) return 0;
        else return ifRtoLsum(root->left, l-root->el) || ifRtoLsum(root->right, l-root->el);
        //else return 0;
        
    }
    bool isBST(BSTNode<T>*root)
    {
//        BSTNode<T>*p=root;
        if(root==NULL) return true;
        if(root->left&&root->right && (root->el>max(root->left)) && (root->el<min(root->right))) return true; 
        else if(root->left!=0&& (root->el>max(root->left))) return true;
        else if(root->right!=0&&(root->el<min(root->right))) return true;
        else return false;
        
    }
    int max(BSTNode<T>*root){
       if(root==0) return 0;
       else {
            int l = max(root->left);
            int r = max(root->right);
            int a = (l>=r)?l:r;
            return (root->el > a)?root->el: a;
        }
    }
     int min(BSTNode<T>*root){
       if(root==0)  return 1000007;
       
       else {
            int l = min(root->left);
            int r = min(root->right);
            int a = (l<=r)?l:r;
            return (root->el < a)?root->el: a;
        }
    }
    void printLOT(BSTNode<T>*root){
        queue<BSTNode<T>*> q;
        if(root!=NULL){
            q.push(root);
            q.push(NULL);
            while(!q.empty()){
                root = q.front();
                q.pop();
                if(root==NULL){
                    cout<<endl;
                    if(!q.empty()) q.push(NULL);
                }
                else {
                    visit(root);
                    if(root->left) q.push(root->left);
                    if(root->right) q.push(root->right);
                }
            }
        }
    }
    //int globmax=1000007;
    //int globmin = 0;
    bool isBSTbest(BSTNode<T>*root, int globmax, int globmin){
        if (root==0) return 1;
        if(root->el >globmin&&root->el<globmax) return 1;
        if(!isBSTbest(root->left, root->el,globmin)||(!isBSTbest(root->right, globmax,root->el))) return 0;
    }
    int maxht(BSTNode<T>*root){
        if(root==NULL) return 0;
        else{
            int a = maxht(root->left);
            int b = maxht(root->right);
            return (a>b)?a+1:b+1;
        }
    }
    bool btident(BSTNode<T>*root1, BSTNode<T>*root2){
       if(!root1&&!root2) return 1;
        else if(((root1->left)&&(!root2->left))||(root1->right&&!root2->right)||(!root1->left&&root2->left)||(!root1->right&&root2->right)) return 0;
        else  if(root1->el!=root2->el) return 0;
        else if(!btident(root1->left, root2->left)||!btident(root1->right,root2->right)) return 0;
       
        else return 1;
    }
    void mirrorT(BSTNode<T>*root){
        if(!root->left&&!root->right) return;
        else {
            BSTNode<T>*tmp = root->left;
            root->left=root->right;
            root->right=tmp;
            if(root->left) mirrorT(root->left);
            if(root->right) mirrorT(root->right); 
        }
    }
    
    BSTNode<T>* leastcom(BSTNode<T>* root, BSTNode<T>*a, BSTNode<T>*b){
        if(root==NULL) return root;
        if(root==a||root==b) return root;
        BSTNode<T>* left = leastcom(root->left, a, b);
        BSTNode<T>* right = leastcom(root->right,a,b);
        
        if(left&&right) return root;
        else return left? left:right;
    }

    
    void find_del(int el){
        BSTNode<T>* p = root;
        while(p!=0){
            if(p->el==el) break;
            else if(p->el>el) p = p->left;
            else p = p->right;
        }
        if(p!=0&&p->el==el) del(p);
        else cout<<"Ele not found"<<endl;
    }
    void del(BSTNode<T>*&node){
        if(!node->left) node = node->right;
        else if(!node->right) node = node->left;
        else {
            BSTNode<T>*prev = node, *temp = node->left;
            while(temp->right!=0) {
                prev = temp;
                temp = temp->right;
            }
            node->el = temp->el;
            if(prev==node) prev->left = temp->left;
            else prev->right = temp->left;
             delete temp;
        }
       
    }

    void revBFS(){
        BSTNode <T>*p =root;
        stack<BSTNode<T>*> s;
        queue<BSTNode<T>*> q;
        if(p!=0){
            q.push(p);
            //s.push(p);
            q.push(NULL);
            while(!q.empty()){
                p = q.front();
                q.pop();
                if(p!=NULL){
                    s.push(p);
                    if(p->right){
                        q.push(p->right);
//                        s.push(p->right);
                    } 
                    if(p->left){
                        q.push(p->left);
//                        s.push(p->left);
                    }
                }
            }
        }
        while(!s.empty()){
            p = s.top();
            s.pop();
            visit (p);
        }
    }
    
    void printancestor(BSTNode<T>* root, BSTNode<T>*p){
        stack<BSTNode<T>*>s;
        if(root!=0){
            s.push(root);
            while(!s.empty()){
                root = s.top();
                s.pop();
                if(root==p){
                    while(!s.empty()) {
                        BSTNode<T>* pp = s.top();
                        s.pop();
                        visit(pp);
                    }
                }
                s.push(root->right);
                s.push(root->left);
             }
        }
    }
    bool samedel(BSTNode<T>*root1, BSTNode<T>*root2){
        if(!root1&&root2) return 0;
        else if(root1&&!root2) return 0;
        else if(!root1&&!root2) return 1;
        else {
            if(root1->el==root2->el) {
                int temp = samedel(root1->left, root2->left);
                if(temp==0) return 0;
                else temp = samedel(root1->right, root2->right);
                return temp;
            }
        }
    }
    void printA(int *a, int n) {
        for (int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    void pri(BSTNode <T>*root, int *p, int pat){
        if(root==0) return ;
        p[pat] = root->el;
        pat++;
        if(!root->left && !root->right) printA(p, pat);
        else {
            pri(root->left, p, pat);
            pri(root->right,p,pat);
        }
    }    
    int Lca(BSTNode<T>*root, int a, int b){
        if(root==0) return 0;
        else if(root->el==a||root->el==b) return root->el;
        else {
        int left, right;
        left = Lca(root->left, a, b);
        right = Lca(root->right,a, b);
        if(left&&right) return root->el;
        else return left?left:right;
        }
    }
    void findrot(int el){
        BSTNode<T>* p =root;
        BSTNode<T>*gr=0, *par=0, *ch=0;
        if(p->el==el) return;
        else if(el<p->el) {
            par = p;
            ch = p->left;
        }
        else {
            par = p;
            ch = p->right;
        }
        if(ch->el==el)return ;
        else {
            gr = p;
            par = ch;
            if(ch->el>el) ch = ch->left;
            else ch = ch->right;
            if(ch->el==el) rotate(gr,par,ch);
            else {
                while(ch->el!=el){
                    gr = par;
                    par=ch;
                    if(ch->el>el) ch = ch->left;
                    else ch = ch->right;
                }
                rotate(gr,par,ch);
            }
        }
    }
    void rotate(BSTNode<T>*gr, BSTNode<T>*par, BSTNode<T>*ch){
        gr->right = ch;
        int k = ch->right->el;
        ch->right = par;
        par->left = new BSTNode<T>(k);
    }
    void createbackbone (BSTNode<T>*root){
        
        //// DSW Algo http://www.smunlisted.com/day-stout-warren-dsw-algorithm.html
    }

    void iterinorder(){
        BSTNode<T>*p=root;
        stack<BSTNode<T>*>s;
        if(p!=0){
            while(true){
                while(p){
                    s.push(p);
                    p=p->left;
                }
                if(s.empty())break;
                p=s.top();
                s.pop();
                visit(p);
                p=p->right;
            }
        }
    }visit(p);
                iterpostorder
    bool isBST(BSTNode<T>*p, int globmax, int globmin){
        if(p==0) return 1;
        else return(p->el>globmin&&p->el<globmax&&isBST(p->left, p->el,globmin)&&isBST(p->right, globmax, p->el));
    }


    BSTNode<T> *root;
      
};



int main(){
    BST<int>B, Ba,b;
    B.insert(10);
    B.insert(5);
    B.insert(15);
    B.insert(3);
    B.insert(7);
    B.insert(12);
    B.insert(17);
    B.insert(4);
    B.insert(11);
    B.insert(13);
    Ba.insert(10);
    Ba.insert(15);
    Ba.insert(5);
    Ba.insert(3);Ba.insert(7);
    Ba.insert(12);Ba.insert(17); 
    cout<<B.isBST(B.root, 1000007, -101011);
    cout<<endl;
    return 0;
}