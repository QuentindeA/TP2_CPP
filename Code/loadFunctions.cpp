void loadFromFile(Catalogue *monCatalogue)
{
    string filePath;
    string newLine;

    cout << "Entrez le nom du fichier :" << endl;
    cin >> filePath;
    ifstream in(filepath);
    in >> newLine;
    while(newLine)
    if (newLine[0] = 's')
        makeTrajetSimple(newLine);
    else if (newLine[0] = 'c')
        makeTrajetCompose(newLine, in);
    else

    monCatalogue.AddTrajet();
}

const TrajetSimple *makeTrajetSimple(string readLine)
{
    char *startPoint = new char[MAX_LENGTH];
    char *endPoint = new char[MAX_LENGTH];
    char *mean = new char[MAX_LENGTH];

    const TrajetSimple *ts = new const TrajetSimple(startPoint, endPoint, mean);

    delete[] startPoint;
    delete[] endPoint;
    delete[] mean;

    return ts;
}
