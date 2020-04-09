package spells;

import exceptions.InvalidCastException;
import units.Demon;
import units.Unit;

public class DemonsCall extends Spell {
    private static int counter = 1;

    public DemonsCall() {
        super("DemonsCall", 50, 0, true);
    }

    public DemonsCall(int actionPoints) {
        super("DemonsCall", 50, actionPoints, true);
    }

    public Demon action() {
        String name = "Slave" + counter;
        Demon slave = new Demon(name);

        counter += 1;
        return slave;
    }
}
