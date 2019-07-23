package units;

import abilities.SoldierAbility;
import actions.SoldierAction;

public class Soldier extends Unit {
    public Soldier(String name) {
        super(name, 150, 30, 0.15, "Soldier", "Alive");
        this.ability = new SoldierAbility(this);
        this.action = new SoldierAction(this);
    }
}
