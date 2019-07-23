package units;

import abilities.VampireAbility;
import actions.VampireAction;

public class Vampire extends Unit {
    public Vampire(String name) {
        super(name, 120, 35, 0.10, "Vampire", "Undead");
        this.ability = new VampireAbility(this);
        this.action = new VampireAction(this);
    }
}
