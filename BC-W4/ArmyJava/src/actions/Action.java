package actions;

import units.Unit;

public abstract class Action {
    protected Unit owner;

    public Action(Unit unit) {
        this.owner = unit;
    }

    public abstract void attack(Unit enemy);
    public abstract void counterAttack(Unit enemy);
}
