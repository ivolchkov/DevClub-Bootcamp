package abilities;

import units.Unit;
import exceptions.*;

public class SoldierAbility extends Ability {
    public SoldierAbility(Unit owner) {
        super(owner);
    }

    public void transform() throws InvalidTransformException {
        throw new InvalidTransformException();
    }

    public void infect(Unit enemy) throws InvalidInfectException {
        throw new InvalidInfectException();
    }
}
