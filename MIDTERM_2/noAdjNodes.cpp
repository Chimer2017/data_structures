void Graph::findVerticesWithNoAdjacentVertices() {
    int stat = 0;
    for ( int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].adj.size() == 0)
        {
            cout << vertices[i].name << " ";
            stat = 1;
        }

    }

    if (stat == 0)
    {
        cout << "Not Found!" << endl;
    }

}
