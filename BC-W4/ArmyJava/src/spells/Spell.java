package spells;

import exceptions.InvalidCastException;
import units.Demon;
import units.Unit;

public abstract class Spell {
    protected String spellName;
    protected int manaCost;
    protected int actionPoints;
    protected boolean isAttack;

    public Spell(String spellName, int manaCost, int actionPoints, boolean isAttack ) {
        this.spellName = spellName;
        this.manaCost = manaCost;
        this.actionPoints = actionPoints;
        this.isAttack = isAttack;
    }

    public String getSpellName() {
        return this.spellName;
    }

    public int getManaCost() {
        return this.manaCost;
    }

    public int getActionPoints() {
        return this.actionPoints;
    }

    public boolean isAttack() {
        return this.isAttack;
    }

    public void action(Unit enemy) throws InvalidCastException {
        throw new InvalidCastException();
    }
    public void heal(Unit target) throws InvalidCastException {
        throw new InvalidCastException();
    }

    public Demon action() throws InvalidCastException {
        throw new InvalidCastException();
    }

}

