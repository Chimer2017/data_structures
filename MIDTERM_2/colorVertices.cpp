void Graph::colorVertices(string sourceVertex) {
    // BFT seems to be best option

    // color all vertices red first

    //standard BFT
    vertex * tmp;
    for ( int i = 0; i < vertices.size(); i++)
    {
        vertices[i].color = "Red";
        if (vertices[i].name  == sourceVertex)
        {
            tmp = &vertices[i];

        }
    }

    //***cout << tmp->name << endl;

    //Now continuing w/ the BFT algo

    tmp->visited = true;

    queue<vertex *> q;

    q.push(tmp);

    vertex * n;


    //scan the queue now


    while(!q.empty())
    {
        //need these two steps to dequeue
        n = q.front();
        q.pop();

        //scan the adj list of each element

        for ( int x = 0; x < n->adj.size(); x++)
        {
            if (!n->adj[x].v->visited)
            {
                n->adj[x].v->visited = true;
                //DELETE LATER *** for Traversal printing
                //***cout << n->adj[x].v->name << endl;
                q.push(n->adj[x].v);
                if (n->color == "Red")
                    n->adj[x].v->color = "Black";
                else
                    n->adj[x].v->color = "Red";

            }
        }

    }




}
