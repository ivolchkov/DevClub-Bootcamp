package units;

import abilities.RogueAbility;
import actions.RogueAction;

public class Rogue extends Unit {
    public Rogue(String name) {
        super(name, 130, 35, 0.2, "Rogue", "Alive");
        this.ability = new RogueAbility(this);
        this.action = new RogueAction(this);
    }
}
