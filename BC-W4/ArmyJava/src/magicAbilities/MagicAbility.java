package magicAbilities;

import exceptions.InvalidCastException;
import exceptions.OutOfManaException;
import spells.Spell;
import units.SpellCaster;
import units.Unit;

public class MagicAbility {
    protected SpellCaster owner;
    protected Spell attackSpell;
    protected Spell healSpell;

    public MagicAbility(SpellCaster owner) {
        this.owner = owner;
    }

    public void setAttackSpell(Spell spell) {
        if ( spell.isAttack() ) {
            this.attackSpell = spell;
        }
    }

    public void setHealSpell(Spell spell) {
        if ( !spell.isAttack() ) {
            this.healSpell = spell;
        }
    }

    public void cast(Unit enemy) throws OutOfManaException, InvalidCastException {
        owner.ensureIsAlive();
        owner.spendMana(this.attackSpell.getManaCost());
        this.attackSpell.action(enemy);
    }

    public void cast() throws OutOfManaException, InvalidCastException {
        throw new InvalidCastException();
    }

    public void heal(Unit target) throws OutOfManaException, InvalidCastException {
        owner.ensureIsAlive();
        owner.spendMana(this.attackSpell.getManaCost());
        this.healSpell.heal(target);
    }

    public void heal() throws OutOfManaException, InvalidCastException {
        owner.ensureIsAlive();
        owner.spendMana(this.attackSpell.getManaCost());
        this.healSpell.heal(owner);
    }
}
