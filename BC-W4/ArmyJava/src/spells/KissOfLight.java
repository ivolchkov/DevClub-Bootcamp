package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class KissOfLight extends Spell {
    public KissOfLight() {
            super("KissOfLight", 100, 120, false);
        }

    public KissOfLight(int actionPoints) {
        super("KissOfLight", 100, actionPoints, false);
    }

    public void heal(Unit unit) throws InvalidCastException {
        unit.addHitPoints(this.actionPoints);
    }
}
