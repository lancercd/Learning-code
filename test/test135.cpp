#include "iostream"
#include "algorithm"
#include "stack"

const int MAXN = 200;
int N, M;
bool graph[MAXN][MAXN] = {0};

int dfn[MAXN] = {0};
int low[MAXN] = {0};
std::stack<int> st;
int timing = 0;

void tarjan(int point){
    st.push(point);
    dfn[point] = low[point] = ++timing;
    for(int i=0; i<N; ++i)
    {
        if(graph[point][i]){
            if(dfn[i] == 0) tarjan(i);
            low[point] = std::min(low[point], low[i]);
        }
    }
    if(dfn[point] == low[point]){
        while(point != st.top()) st.pop();
        st.pop(); //pop self
    }
}

void showRes();
void showInput();

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    std::cin >> N >> M;
    int a,b;
    for(int i=0; i<M; ++i)
    {
        std::cin >> a >> b;
        graph[a-1][b-1] = 1;
    }

    showInput();
    std::cout << std::endl;

    for(int i=0; i<N; ++i)
    {
        if(!dfn[i]) tarjan(i);
    }

    showRes();
    return 0;
}

void showRes(){
    for(int i=0; i<N; ++i)
    {
        std::cout << dfn[i] << " ";
    }
    std::cout << std::endl;
    for(int i=0; i<N; ++i)
    {
        std::cout << low[i] << " ";
    }
}

void showInput(){
    for(int i = 0;  i < N; ++i){
        for(int j = 0;  j < N; ++j){
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
