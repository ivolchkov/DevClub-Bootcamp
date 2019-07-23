package units;

import abilities.WerewolfAbility;
import actions.WerewolfAction;

public class Werewolf extends Unit {
    public Werewolf(String name) {
        super(name, 150, 30, 0.2, "Werewolf", "Alive");
        this.ability = new WerewolfAbility(this);
        this.action = new WerewolfAction(this);
    }
}
