package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class KissOfLight extends Spell {
        public KissOfLight() {
            super("KissOfLight", 100, 120, false);
        }

        public void action(Unit enemy) throws InvalidCastException {
            throw new InvalidCastException();
        }

        public void heal(Unit unit) throws InvalidCastException {
            unit.addHitPoints(this.actionPoints);
        }
}