package units;

import abilities.BerserkerAbility;
import actions.BerserkerAction;

public class Berserker extends Unit {
    public Berserker(String name) {
        super(name, 170, 35, 1, "Berserker", "Alive");
        this.ability = new BerserkerAbility(this);
        this.action = new BerserkerAction(this);
    }
}
