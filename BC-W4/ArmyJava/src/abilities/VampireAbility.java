package abilities;

import units.*;
import actions.VampireAction;
import states.State;
import exceptions.*;

public class VampireAbility extends Ability {
    public VampireAbility(Unit owner) {
        super(owner);
    }

    public void transform() throws InvalidTransformException {
        throw new InvalidTransformException();
    }

    public void infect(Unit enemy) throws InvalidInfectException {
        if ( !(enemy.getAbility() instanceof VampireAbility) && !(enemy.getAbility() instanceof WerewolfAbility) ) {
            String title  = enemy.getTitle() + "(turned)";

            enemy.setAbility(new VampireAbility(enemy));
            enemy.setAction(new VampireAction(enemy));
            enemy.setState(new State(enemy.getName(), owner.getHitPointsLimit(), owner.getDamage(), owner.getMagicResist(), title, owner.getType()));
        } else {
            throw new InvalidInfectException();
        }
    }
}
