void Graph::shortestPath(string source, string destination, string intermediate) {
     // BFT seems to be best option

    // color all vertices red first

    //standard BFT
    vertex * startV;
    // vertex * endV;
    // vertex * midV;
    for ( int i = 0; i < (int)vertices.size(); i++)
    {
        vertices[i].visited = false;
        if (vertices[i].name  == source)
        {
            startV = &vertices[i];

        }
        // if(vertices[i].name == destination)
        // {
        //     endV = &vertices[i];
        // }
        // if(vertices[i].name == intermediate)
        // {
        //     midV = &vertices[i];
        // }
    }

    //cout << startV->name << endl;

    //Now continuing w/ the BFT algo

    startV->visited = true;

    queue<vertex *> q;

    q.push(startV);

    vertex * n;
    vertex * found = NULL;
    int stat = 0;


    //scan the queue now


    while(!q.empty())
    {
        //need these two steps to dequeue
        n = q.front();
        q.pop();

        //scan the adj list of each element

        for ( int x = 0; x < (int)n->adj.size(); x++)
        {
            if (!n->adj[x].v->visited)
            {
                n->adj[x].v->prev = n;
                if (n->adj[x].v->name == destination && stat == 0)
                {
                    //return n->adj[x].v;
                    //cout << "found the dest";
                    found = n->adj[x].v;
                    stat = 1;
                    vertex * current, * tmp;
                    current = found;

                    while (current->name != source)
                    {
                    tmp = current;
                    //cout << "Current: " << current->name << " " << "Prev: " << current->prev->name << endl;
                    if (current->name == intermediate)
                    {
                        cout << "Yes" << endl;
                        return;
                    }
                    current = tmp->prev;
                    }
                    cout << "No" << endl;


                }
                else
                {
                    n->adj[x].v->visited = true;
                    //cout << n->adj[x].v->name << endl;
                    q.push(n->adj[x].v);
                }


            }
        }

    }
   //cout << found->name << endl;







}
