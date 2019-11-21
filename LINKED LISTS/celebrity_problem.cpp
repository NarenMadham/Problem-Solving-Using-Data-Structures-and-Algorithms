// The task is to complete this function
// M[][]: input matrix
// n: size of matrix (n*n)

bool knows(int M[MAX][MAX], int a, int b){
    if(M[a][b] == 1){
        return true;
    }else{
        return false;
    }
}

int getId(int M[MAX][MAX], int n)
{
    stack<int> st;
    for(int i = n-1; i>=0;i--){
        st.push(i);
    }
    while(st.size() != 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(knows(M, a, b)){
            st.push(b);
        }else{
            st.push(a);
        }
    }
    int id = st.top();
    for(int i = 0; i < n;i++){
        if(i != id){
            if(M[id][i] == 0){
                continue;
            }else{
                return -1;
            }
        }
    }
    
    for(int i = 0; i < n;i++){
        if(i != id){
            if(M[i][id] == 1){
                continue;
            }else{
                return -1;
            }
        }
    }
    return id;
}
    
    
    
    
    
    