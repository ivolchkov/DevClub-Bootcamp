package magicAbilities;

import exceptions.InvalidCastException;
import exceptions.OutOfManaException;
import units.SpellCaster;
import units.Unit;

public class PriestMagicAbility extends MagicAbility {
    public PriestMagicAbility(SpellCaster owner) {
        super(owner);
    }

    public void cast(Unit enemy) throws OutOfManaException, InvalidCastException {
        owner.ensureIsAlive();
        owner.spendMana(this.attackSpell.getManaCost());
        this.attackSpell.action(enemy);

        if ( enemy.getType().equals("Undead") ) {
            this.attackSpell.action(enemy);
        }
    }
}
