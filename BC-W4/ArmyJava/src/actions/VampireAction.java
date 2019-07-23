package actions;

import exceptions.InvalidInfectException;
import units.Unit;
import java.util.Random;

public class VampireAction extends Action {
    public VampireAction(Unit owner) {
        super(owner);
    }

    public void attack(Unit enemy) {
        Random attackRange = new Random();
        Random infection = new Random();
        int infectChance = infection.nextInt(101);
        int range = this.owner.getDamage() - 5;
        int attackPoints = attackRange.nextInt(10) + range;

        if ( infectChance <= 30 ) {
            try {
                this.owner.infect(enemy);
            } catch (InvalidInfectException e) {
               e.printStackTrace();
            }
        }

        enemy.takeDamage(attackPoints);
        owner.addHitPoints(attackPoints / 3);
    }

    public void counterAttack(Unit enemy) {
        Random cAttackRange = new Random();
        int range = (this.owner.getDamage() / 2) - 5;
        int cAttackPoints = cAttackRange.nextInt(5) + range;

        enemy.takeDamage(cAttackPoints);
        owner.addHitPoints(cAttackPoints / 3);
    }

}
