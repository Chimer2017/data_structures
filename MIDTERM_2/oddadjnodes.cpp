void Graph::findOddAdjacent(int startVertex) {
	vertex *start;
	for (int i = 0; i < (int)vertices.size(); i++) {
		vertices[i].visited = false;
		if (vertices[i].value == startVertex) {
			start = &vertices[i];
		}
	}

	queue<vertex*> Q;
	Q.push(start);
	start->visited = true;
	cout << start->value << " ";
	while (!Q.empty()) {
		vertex *node = Q.front();
		Q.pop();
		for (int x = 0; x < (int)node->adj.size(); x++) {

            if (!node->adj[x].v->visited)
            {
                node->adj[x].v->visited = true;
                //DELETE LATER
                if ((int)node->adj[x].v->value%2 != 0)
                    cout << node->adj[x].v->value << " ";
                Q.push(node->adj[x].v);
            }

		}
	}
}
