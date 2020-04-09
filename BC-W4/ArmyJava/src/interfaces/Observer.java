package interfaces;

import exceptions.UnitIsDead;
import units.Unit;

public interface Observer {
    void update(Unit enemy) throws UnitIsDead;
}
