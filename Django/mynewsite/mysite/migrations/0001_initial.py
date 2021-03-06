# Generated by Django 3.2.12 on 2022-03-08 07:33

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='NewTable',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('bigint_f', models.BigIntegerField()),
                ('bool_f', models.BooleanField()),
                ('date_f', models.DateField(auto_now=True)),
                ('char_f', models.CharField(max_length=200, unique=True)),
                ('datetime_f', models.DateTimeField(auto_now_add=True)),
                ('decimal_f', models.DecimalField(decimal_places=2, max_digits=10)),
                ('float_f', models.FloatField(null=True)),
                ('int_f', models.IntegerField(default=2022)),
                ('text_f', models.TextField()),
            ],
        ),
    ]
