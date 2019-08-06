package spells;

import exceptions.InvalidCastException;
import units.Unit;

public class DragonFlame extends Spell {
    public DragonFlame() {
        super("DragonFlame", 55, 80, true);
    }

    public void action(Unit enemy) throws InvalidCastException {
        enemy.takeMagicDamage(this.actionPoints);
    }

    public void heal(Unit unit) throws InvalidCastException {
        throw new InvalidCastException();
    }
}
