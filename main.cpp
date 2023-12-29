#include <fstream>
#include <iostream>
#include <memory>

using std::dynamic_pointer_cast;
using std::fstream;
using std::cout, std::endl;

#include "Business/ParserFactory.hpp"
#include "Business/RectangleParser.hpp"
#include "Business/SquareParser.hpp"
#include "Business/CircleParser.hpp"
#include "Business/SortingShapesPerformer.hpp"
#include "Business/SortingShapesByAreaStrategy.hpp"

#include "Entity/IShape.hpp"

#include "UI/ShapesDisplayer.hpp"
#include "UI/DisplayShapesTableStrategy.hpp"

#include "Helper/Utils.hpp"

int main()
{
    try
    {
        ParserFactory parserFactory;

        // Read the file --> UPGRADEABLE: Use DAO class
        fstream fin("../Data/shapes.txt");

        vector<shared_ptr<Object>> shapes;

        string line;
        cout << line << endl;
        getline(fin, line);
        int numOfShapes = stoi(line);

        for (int i = 0; i < numOfShapes; i++)
        {
            getline(fin, line);

            // Square: a=12
            vector<string> tokens = Utils::String::split(line, ":");

            // Create parser
            shared_ptr<IParsable> parser = parserFactory.create(tokens[0]);

            // Parse the data
            shared_ptr<IShape> shape = dynamic_pointer_cast<IShape>(parser->parse(tokens[1]));

            // Add the shape to the vector
            shapes.push_back(shape);
        }

        SortingShapesPerformer sortingShapesPerformer;
        sortingShapesPerformer.performSorting(shapes, Criteria::AREA);

        vector<string> headers = {};
        vector<int> widths = {
            13, 15, 11
        };

        shared_ptr<ShapesDisplayer> shapesDisplayer = ShapesDisplayer::getInstance();
        shapesDisplayer->signWith(make_shared<DisplayShapesTableStrategy>(headers, widths));
        shapesDisplayer->display(shapes, DisplayMode::TABLE);
    }
    catch (const std::invalid_argument& ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
    }
}