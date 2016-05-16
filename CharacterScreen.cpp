#include "CharacterScreen.h"
#include "BattleScreen.h"
#include "Selector.h"

int CharacterScreen::open(sf::RenderWindow* window) {
    readyB = Button(325,400,150,50,sf::Color(0,0,0,255),"READY");
    johnB = Button(5,5,100,100,sf::Color(0,0,255,255),"JOHN");
    roseB = Button(5,395,100,100,sf::Color(128,0,128,255),"ROSE");
    daveB = Button(695,5,100,100,sf::Color(255,0,0,255),"DAVE");
    jadeB = Button(695,395,100,100,sf::Color(0,255,0,255),"JADE");

    dispList.push_back(&readyB);
    dispList.push_back(&johnB);
    dispList.push_back(&roseB);
    dispList.push_back(&daveB);
    dispList.push_back(&jadeB);

    SelectorGrid<Button> johnG = SelectorGrid<Button> (&johnB);
    SelectorGrid<Button> roseG = SelectorGrid<Button> (&roseB);
    SelectorGrid<Button> daveG = SelectorGrid<Button> (&daveB);
    SelectorGrid<Button> jadeG = SelectorGrid<Button> (&jadeB);

    johnG.setXPos(5);
    johnG.setYPos(5);
    johnG.setWidth(100);
    johnG.setHeight(100);
    johnG.setUpward(&roseG);
    johnG.setDownward(&roseG);
    johnG.setLeftward(&daveG);
    johnG.setRightward(&daveG);

    roseG.setXPos(5);
    roseG.setYPos(395);
    roseG.setWidth(100);
    roseG.setHeight(100);
    roseG.setUpward(&johnG);
    roseG.setDownward(&johnG);
    roseG.setLeftward(&jadeG);
    roseG.setRightward(&jadeG);

    daveG.setXPos(695);
    daveG.setYPos(5);
    daveG.setWidth(100);
    daveG.setHeight(100);
    daveG.setUpward(&jadeG);
    daveG.setDownward(&jadeG);
    daveG.setLeftward(&johnG);
    daveG.setRightward(&johnG);

    jadeG.setXPos(695);
    jadeG.setYPos(395);
    jadeG.setWidth(100);
    jadeG.setHeight(100);
    jadeG.setUpward(&daveG);
    jadeG.setDownward(&daveG);
    jadeG.setLeftward(&roseG);
    jadeG.setRightward(&roseG);

    Selector<Button> p1Selector = Selector<Button>(&johnG);
    dispList.push_back(&p1Selector);

    bool done = false;

    while(!done) {
        sf::Event event;
        while(window->pollEvent(event)) {
            if(event.type == sf::Event::Closed) window->close(), done = true;
            if(event.type == sf::Event::MouseButtonPressed) {
                if(readyB.pointOnBox(event.mouseButton.x,event.mouseButton.y)) {
                    done = true;
                    //initialize players, send to battle
                    BattleScreen().open(window);
                }//open the battle screen
                //other buttons for selecting a character go here.
            }
            if(event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    p1Selector.move(Selector<Button>::UP);
                    break;
                case sf::Keyboard::Down:
                    p1Selector.move(Selector<Button>::DOWN);
                    break;
                case sf::Keyboard::Right:
                    p1Selector.move(Selector<Button>::RIGHT);
                    break;
                case sf::Keyboard::Left:
                    p1Selector.move(Selector<Button>::LEFT);
                    break;
                }
            }
        }
        if(done) return 0;
        window->clear(sf::Color::Black);
        for(std::list<DisplayObject*>::iterator it = dispList.begin(); it != dispList.end(); it++)
            (*it)->drawSelf(window);
        window->display();
    }
    return 0;
}
