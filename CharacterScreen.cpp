#include "CharacterScreen.h"
#include "BattleScreen.h"
#include "Selector.h"
#include "ResourceManager.h"

int CharacterScreen::open(sf::RenderWindow* window) {
    readyB = Button(325,425,150,50,sf::Color(83,83,83,255),"READY");
    johnB = Button(200,0,200,200,sf::Color::White,"");
    johnB.getShape()->setTexture(&ResourceManager::JohnStand);
    roseB = Button(200,200,200,200,sf::Color::White,"");
    roseB.getShape()->setTexture(&ResourceManager::RoseStand);
    daveB = Button(400,0,200,200,sf::Color::White,"");
    daveB.getShape()->setTexture(&ResourceManager::DaveStand);
    jadeB = Button(400,200,200,200,sf::Color::White,"");
    jadeB.getShape()->setTexture(&ResourceManager::JadeStand);


    dispList.push_back(&readyB);
    dispList.push_back(&johnB);
    dispList.push_back(&roseB);
    dispList.push_back(&daveB);
    dispList.push_back(&jadeB);

    SelectorGrid<Button> johnG = SelectorGrid<Button> (&johnB);
    SelectorGrid<Button> roseG = SelectorGrid<Button> (&roseB);
    SelectorGrid<Button> daveG = SelectorGrid<Button> (&daveB);
    SelectorGrid<Button> jadeG = SelectorGrid<Button> (&jadeB);

    johnG.setXPos(210);
    johnG.setYPos(10);
    johnG.setWidth(180);
    johnG.setHeight(180);
    johnG.setUpward(&roseG);
    johnG.setDownward(&roseG);
    johnG.setLeftward(&daveG);
    johnG.setRightward(&daveG);

    roseG.setXPos(210);
    roseG.setYPos(210);
    roseG.setWidth(180);
    roseG.setHeight(180);
    roseG.setUpward(&johnG);
    roseG.setDownward(&johnG);
    roseG.setLeftward(&jadeG);
    roseG.setRightward(&jadeG);

    daveG.setXPos(410);
    daveG.setYPos(10);
    daveG.setWidth(180);
    daveG.setHeight(180);
    daveG.setUpward(&jadeG);
    daveG.setDownward(&jadeG);
    daveG.setLeftward(&johnG);
    daveG.setRightward(&johnG);

    jadeG.setXPos(410);
    jadeG.setYPos(210);
    jadeG.setWidth(180);
    jadeG.setHeight(180);
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
        window->clear(sf::Color(238,238,238,255));
        for(std::list<DisplayObject*>::iterator it = dispList.begin(); it != dispList.end(); it++)
            (*it)->drawSelf(window);
        window->display();
    }
    return 0;
}
