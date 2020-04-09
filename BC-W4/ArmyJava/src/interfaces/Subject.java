package interfaces;

import exceptions.UnitIsDead;

public interface Subject {
    void attach(Observer observer);
    void detach(Observer observer);
    void notifyObservers() throws UnitIsDead;

}
