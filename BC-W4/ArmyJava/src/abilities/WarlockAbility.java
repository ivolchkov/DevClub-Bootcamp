package abilities;

import exceptions.InvalidInfectException;
import exceptions.InvalidTransformException;
import units.Unit;

public class WarlockAbility extends Ability {
    public WarlockAbility(Unit owner) {
        super(owner);
    }

    public void transform() throws InvalidTransformException {
        throw new InvalidTransformException();
    }

    public void infect(Unit enemy) throws InvalidInfectException {
        throw new InvalidInfectException();
    }
}
