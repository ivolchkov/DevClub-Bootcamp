package units;

import abilities.DemonAbility;
import actions.DemonAction;

public class Demon extends Unit {
    public Demon(String name) {
        super(name, 100, 20, 0.1, "Demon", "Undead");
        this.ability = new DemonAbility(this);
        this.action = new DemonAction(this);
    }
}
