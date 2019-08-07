package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class AquaSplash extends Spell {
    public AquaSplash() {
        super("AquaSplash", 45, 65, true);
    }

    public AquaSplash(int actionPoints) {
        super("AquaSplash", 45, actionPoints, true);
    }

    public void action(Unit enemy) throws InvalidCastException {
        enemy.takeMagicDamage(this.actionPoints);
    }

    public void heal(Unit unit) throws InvalidCastException {
        throw new InvalidCastException();
    }

}
