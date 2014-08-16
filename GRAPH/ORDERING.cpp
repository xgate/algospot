#include <iostream>
#include <queue>
#include <string>
#include <cstring>
 
using namespace std;
 
#define MAX_VT 26
 
typedef struct Vertice {
    int  in;
    char job;
    char out[MAX_VT];
    // The comparison operator used to order the
    // priority queue.
    bool operator<(const Vertice &v) const {
        return (job > v.job);
    }
} Vertice;
 
int main()
{
    // graph: set of vertice
    Vertice graph[MAX_VT];
     
    int t;
    cin >> t;
 
    while (t--)
    {
        priority_queue<Vertice> jobq;
        int jobNum, nDepend;
 
        memset(graph, 0, sizeof(Vertice)*MAX_VT);
 
        cin >> jobNum >> nDepend;
 
        // set job name
        for (int i=0; i<jobNum; i++) {
            graph[i].job = i+'A';
        }
        // draw edge : (ex) A  ----> B
        for (int i=0; i<nDepend; i++)
        {
            string jobs;
             
            cin >> jobs;
            int vId_in  = jobs[0]-'A';
            int vId_out = jobs[1]-'A';
 
            // check direction (A? B? C? ..)
            graph[vId_in].out[vId_out] = 1;
            // increase in-degree
            graph[vId_out].in++;
        }
 
        // insert jobs to q, only in-degree=0
        for (int i=0; i<jobNum; i++) {
            if (graph[i].in == 0) {
                jobq.push(graph[i]);
            }
        }
 
        // pop jobs and print
        while (!jobq.empty())
        {
            Vertice v;
 
            v = jobq.top();
            jobq.pop();
             
            cout << v.job;
            for (int i=0; i<jobNum; i++)
            {
                // when have next job
                if (v.out[i]) {
                    // decrease next job's in-degree
                    graph[i].in--;
                    // ok!! now job can be started
                    if (graph[i].in == 0)
                        jobq.push(graph[i]);
                }
            }
        }
 
        cout << endl;
    }
}
