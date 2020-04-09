package magicAbilities;

import exceptions.InvalidCastException;
import exceptions.OutOfManaException;
import units.SpellCaster;


public class WarlockMagicAbility extends MagicAbility {
    public WarlockMagicAbility(SpellCaster owner) {
        super(owner);
    }

    public void cast() throws OutOfManaException, InvalidCastException {
        owner.ensureIsAlive();
        owner.spendMana(this.attackSpell.getManaCost());
        owner.createDemon(this.attackSpell.action());
    }
}
